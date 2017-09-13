#include <string.h>

#include "p2p.h"
#include "tcp.h"
#include "error.h"
#include "windows.h"
#include "verification.h"

#define BUFF_SIZE 15
void empty_buffer() {
    char c = ' ';
    while ( (c = getc(stdin)) != '\n' && c != EOF ) ;
}

bool choice() {
    unsigned int choice = 0;

    printf("P2P Library - By Reynaud Nicolas\n");
    printf("\t[1] - Start as a server\n");
    printf("\t[2] - Connect to a server\n");

    do {
        printf("\r--------------------- Choice ? ");
        choice = getc(stdin) - '1';
        empty_buffer(); 
    } while (choice >= 2);

    return choice;
}

void ask(char *txt, char *output) {
    int i = 0;
    char c = ' ';

    printf("%s", txt);
    for ( i = 0; i < BUFF_SIZE && ((c = getc(stdin)) != '\n'); i++ )
        output[i] = c;
    output[i] = '\0';

}

void ask_config_server() {
    char input[BUFF_SIZE] = {0};
    int  port = 0;
    
    do {
        ask("[Server] Start on port : ", input);
        port = atoi(input); 
        if ( verif_port(port) == TRUE ) break;
    } while (TRUE);
    s.port = port;
}

void ask_config_client() {
    char input[BUFF_SIZE] = {0};
    int  port = 0;

    do {
        ask("[Client] Server Ip Adress ? ", input);
        if ( verif_ip(input) == TRUE ) break;
    } while (TRUE);
    strcpy(s.ip_addr, input);
    
    do {
        ask("[Client] Port Server ? ", input);
        port = atoi(input); 
        if ( verif_port(port) == TRUE ) break;
    } while (TRUE);
    s.port = port;
}

void create_server() {
    int optionVal = 1;
    size_t sock_info_size = sizeof(SOCKADDR_IN);

    s.socket_info.sin_family = AF_INET;
    s.socket_info.sin_addr.s_addr = INADDR_ANY;
    s.socket_info.sin_port = htons(s.port);    
    
    if ( (s.id_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        QUIT_MSG("Can't create the socket : ");
    }

    if ( setsockopt(s.id_socket, SOL_SOCKET, SO_REUSEADDR, (char *)&optionVal, sizeof(optionVal)) == SOCKET_ERROR ) {
        QUIT_MSG("Can't set socket option : ");
    }
    
    if ( bind(s.id_socket, (struct sockaddr *)&s.socket_info, sock_info_size) == -1) {
        QUIT_MSG("Can't bind the socket : ");
    }
    
    /* Hey listen */
    if ( listen(s.id_socket, 1) == -1 ) {
        QUIT_MSG("Socket listen trouble : ");
    }

    serv = s.id_socket;
    s.id_socket = accept(serv, (struct sockaddr*) &s.socket_info, (__socklen_t *)&sock_info_size);
 
    strcpy(s.ip_addr, inet_ntoa(s.socket_info.sin_addr));
    s.port = ntohs(s.socket_info.sin_port);

    DEBUG_MSG("New Player [%s:%d]\n", s.ip_addr, s.port);
}

bool connection() {
    char tmp[50] = { 0 };
    initWindows(); // Init socket windows

    serv = INVALID_SOCKET;
    s.id_socket = INVALID_SOCKET;

    if ( choice() == 1 ) {
        ask_config_client();

        if ( tcp_start() == FALSE )
            ERROR_MSG("Impossible to connect to [%s:%d] : ", s.ip_addr, s.port);
    } else {
        ask_config_server();
        create_server();
    }

    return TRUE;
}

bool disconnect() {
    (void) tcp_stop();

    endWindows(); // End socket windows

    return TRUE;
}
