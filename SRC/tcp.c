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

    c.id_socket = socket(AF_INET,SOCK_STREAM,0);
    
    c.socket_info.sin_family = AF_INET;
    c.socket_info.sin_port = htons(c.port);

    if( (h = gethostbyname(c.ip_addr)) == NULL ) return FALSE; /* Can't connect */

    memcpy(&c.socket_info.sin_addr.s_addr, h->h_addr, h->h_length);
    
    if (connect(c.id_socket, (struct sockaddr *)&(c.socket_info), sizeof(c.socket_info)) < 0){
        closesocket(c.id_socket);
        return FALSE;
    }
    
    return TRUE;
}

bool tcp_stop() {
    closesocket(c.id_socket);

    strcpy(c.ip_addr, "");
    c.port = 0;

    c.id_socket = INVALID_SOCKET;
    return TRUE;
}

int tcp_action_delay(void *_data, int _data_length, int _second, int _millisecond ) {
    struct timeval tv;
    
    tv.tv_sec = _second;
    tv.tv_usec = _millisecond; 
    
    setsockopt(c.id_socket, SOL_SOCKET, SO_RCVTIMEO, (char *)&tv,sizeof(struct timeval)); /* Set a timer on respond */
    return tcp_recv(_data, _data_length);
} 
