#ifndef STRUCT_CONFIG_H
#define STRUCT_CONFIG_H

#include "socket.h"

typedef struct Configuration {
	SOCKET id_socket;           /* id de la socket */
	SOCKADDR_IN socket_info;    /* Host */
    char ip_addr[16];           /* XXX.XXX.XXX.XXX\0 */
    int port;               /* XXXXX\0 */
} Configuration;

typedef Configuration Client; 

#endif


