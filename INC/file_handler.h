//----------------------------------------------------------
// AUTEUR : REYNAUD Nicolas                                 |
// FICHIER : gestion_fichier.h                 		     |
//----------------------------------------------------------

#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#include <netinet/in.h>
#include <string.h>

#include "error.h"
#include "struct_config.h"

#define LINE_SIZE 512

/* Load a configuration */
bool load_configuration(Configuration *_config, const char *_path);

#endif 

