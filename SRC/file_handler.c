// -------------------------------------------------------- 
// AUTEUR : REYNAUD Nicolas                                 |
// FICHIER : gestion_fichier.c                              |
// -------------------------------------------------------- 

#include <netdb.h>
#include "verification.h"
#include "file_handler.h"

char *start_with(char *s1, char *s2) {
	for ( ; *s1 == *s2; s1++, s2++)
		if (*s1 == '\0')
			return s2;

	if (*s1 == '\0')
		return s2;
	return NULL;
}

bool load_configuration(Configuration *_config, const char *_path) {
	char *ret;
	
	char read_line[LINE_SIZE];

	FILE* file = fopen(_path, "r");
	while(fgets(read_line, LINE_SIZE, file) != NULL){
		if ( strchr (read_line, '#') == NULL ) { 
			if((ret = strchr(read_line, '\r')) != NULL) *ret = '\0';
			if((ret = strchr(read_line, '\n')) != NULL) *ret = '\0';

			if ( (ret = start_with("Ip:",read_line)) != NULL ) { 
				if (verif_ip(ret) == FALSE)	
					return FALSE;
		
                strcpy(_config->ip_addr, ret);
			}

			if ( (ret = start_with("Port:",read_line)) != NULL) {
                _config->port = atoi(ret);
				if (verif_port(_config->port) == FALSE ) 
                    return FALSE;
            }
		}
	}

	fclose(file);
	return TRUE;
}

