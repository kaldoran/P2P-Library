#ifndef P2P_H
#define P2P_H

#include "boolean.h"
#include "struct_config.h"

Sock s; // please forgive me, it's for sake of simplicity for user
SOCKET serv;
#define tcp_send(Y, Z) send(s.id_socket, Y, Z, 0);
#define tcp_recv(Y, Z) recv(s.id_socket, Y, Z, 0);    

bool connection();

bool disconnect();

#endif

