//----------------------------------------------------------
// AUTEUR : REYNAUD Nicolas                                 |
// FICHIER : tcp.h                                          |
//----------------------------------------------------------

#ifndef TCP_H
#define TCP_H

#define SEND 0
#define RECEIVED 1

#include "socket.h"
#include "boolean.h"
#include "struct_config.h"

#define tcp_send(X, Y, Z) send(X.id_socket, Y, Z, 0);
#define tcp_recv(X, Y, Z) recv(X.id_socket, Y, Z, 0);    

/** Connects to a Client.
 * 
 *  %param c: Client to connect to.
 * 
 *  %return: TRUE if the connection succeded,
 *           FALSE otherwise.
 */
bool tcp_start(Client *_c);

/** Stop connexion
 * 
 *  %param c: Client to connect to.
 * 
 *  %return: TRUE if the connection succeded,
 *           FALSE otherwise.
 */
bool tcp_stop(Client *_c);

/** Receives data from a Client but with a timer on received
 * 
 *  %param c: Client considered.
 *  %param data: Data to send or to receive.
 *  %param data_length: Number of bits in the data.
 *  %param second : Number of second to wait
 *  %param millisecond : Number of millisecond to wait
 * 
 *  %return: the number of bit received,
 */
int tcp_action_delay(Client c, void *data, int data_length, int second, int millisecond );

#endif /* TCP_H included */
