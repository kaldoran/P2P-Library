#ifndef P2P_H
#define P2P_H

#include "boolean.h"
#include "struct_config.h"

Client c; // please forgive me, it's for sake of simplicity for user

#define tcp_send(Y, Z) send(c.id_socket, Y, Z, 0);
#define tcp_recv(Y, Z) recv(c.id_socket, Y, Z, 0);    

bool connection(const char* filename);

bool disconnect();

#endif

