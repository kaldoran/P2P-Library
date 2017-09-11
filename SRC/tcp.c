//----------------------------------------------------------
// AUTEUR : REYNAUD Nicolas                                 |
// FICHIER : tcp.c                                          |
//----------------------------------------------------------

#include <string.h>

#include "tcp.h"
#include "error.h"
#include "socket.h"

bool tcp_start(Client *_c) {

    struct hostent *h;

    _c->id_socket = socket(AF_INET,SOCK_STREAM,0);
    
    _c->socket_info.sin_family = AF_INET;
    _c->socket_info.sin_port = htons(_c->port);

    if( (h = gethostbyname(_c->ip_addr)) == NULL ) return FALSE; /* Can't connect */

    memcpy(&_c->socket_info.sin_addr.s_addr, h->h_addr, h->h_length);
    
    if (connect(_c->id_socket, (struct sockaddr *)&(_c->socket_info), sizeof(_c->socket_info)) < 0){
        closesocket(_c->id_socket);
        return FALSE;
    }
    
    return TRUE;
}

bool tcp_stop(Client *_c) {
    closesocket(_c->id_socket);

    strcpy(_c->ip_addr, "");
    _c->port = 0;

    _c->id_socket = INVALID_SOCKET;
    return TRUE;
}

int tcp_action_delay(Client _c, void *_data, int _data_length, int _second, int _millisecond ) {
    struct timeval tv;
    
    tv.tv_sec = _second;
    tv.tv_usec = _millisecond; 
    
    setsockopt(_c.id_socket, SOL_SOCKET, SO_RCVTIMEO, (char *)&tv,sizeof(struct timeval)); /* Set a timer on respond */
    return tcp_recv(_c, _data, _data_length);
} 
