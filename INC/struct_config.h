#ifndef STRUCT_CONFIG_H
#define STRUCT_CONFIG_H

typedef struct Configuration {
	int id_socket;	  /* id de la socket */
	in_addr_t ip;     /* Host */
	in_port_t port;   /* Port pour la connection */
} Configuration;

#endif


