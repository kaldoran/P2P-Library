//----------------------------------------------------------
// AUTEUR : REYNAUD Nicolas                                 |
// FICHIER : tcp.c                                          |
//----------------------------------------------------------

#include <string.h>

#include "p2p.h"
#include "tcp.h"
#include "error.h"
#include "socket.h"

bool tcp_start() {

    struct hostent *h;

    s.id_socket = socket(AF_INET,SOCK_STREAM,0);
    
    s.socket_info.sin_family = AF_INET;
    s.socket_info.sin_port = htons(s.port);

    if( (h = gethostbyname(s.ip_addr)) == NULL ) return FALSE; /* Can't connect */

    memcpy(&s.socket_info.sin_addr.s_addr, h->h_addr, h->h_length);
    
    if (connect(s.id_socket, (struct sockaddr *)&(s.socket_info), sizeof(s.socket_info)) < 0){
        closesocket(s.id_socket);
        return FALSE;
    }
    
    return TRUE;
}

bool tcp_stop() {
    if ( s.id_socket != INVALID_SOCKET ) 
        closesocket(s.id_socket);
    
    if ( serv != INVALID_SOCKET )
        closesocket(serv);

    strcpy(s.ip_addr, "");
    s.port = 0;

    s.id_socket = INVALID_SOCKET;
    return TRUE;
}

int tcp_action_delay(void *_data, int _data_length, int _second, int _millisecond ) {
    struct timeval tv;
    
    tv.tv_sec = _second;
    tv.tv_usec = _millisecond; 
    
    setsockopt(s.id_socket, SOL_SOCKET, SO_RCVTIMEO, (char *)&tv,sizeof(struct timeval)); /* Set a timer on respond */
    return tcp_recv(_data, _data_length);
} 
