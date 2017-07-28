// -------------------------------------------------------- 
// AUTEUR : REYNAUD Nicolas                                 |
// FICHIER : gestion_fichier.c                              |
// -------------------------------------------------------- 

#include <netdb.h>
#include "file_handler.h"

char * startWith(char *s1, char *s2) {
	for ( ; *s1 == *s2; s1++, s2++)
		if (*s1 == '\0')
			return s2;

	if (*s1 == '\0')
		return s2;
	return NULL;
}

Configuration *new_configuration() {
	Configuration *config;
	if ((config = calloc(1, sizeof *config)) == NULL)
		QUIT_MSG("Erreur : Probleme d'allocation de la structure de la configuration");
	
	return config;
}

void load_configuration(Configuration *_config, char *_path) {
	char *ret;
	
	struct hostent *h;
	char read_line[LINE_SIZE];

	FILE* file = fopen(_path, "r");
	while(fgets(read_line, LINE_SIZE, file) != NULL){
		if ( strchr (read_line, '#') == NULL ) { 
			if((ret = strchr(read_line, '\r')) != NULL) *ret = '\0';
			if((ret = strchr(read_line, '\n')) != NULL) *ret = '\0';

			if ( (ret = startWith("Ip:",read_line)) != NULL ) { 
				if((h = gethostbyname(ret)) == NULL)	
					return;
				else 
					memcpy(&_config->ip, h->h_addr, h->h_length);
			}

			if ( (ret = startWith("Port:",read_line)) != NULL)
				_config->port = htons((in_port_t)atoi(ret));
		}
	}

	fclose(file);
	return;
}

