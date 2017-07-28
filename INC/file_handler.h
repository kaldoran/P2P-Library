//----------------------------------------------------------
// AUTEUR : REYNAUD Nicolas                                 |
// FICHIER : gestion_fichier.h                 		     |
//----------------------------------------------------------

#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#include <netinet/in.h>
#include <string.h>

#include "globale.h"
#include "struct_config.h"

#define LINE_SIZE 512
#define ADRESS_CONFIG "BDD/config.txt" /* adresse fichier texte de la configuration */

/* Allocate the neww configuration */
Configuration *new_configuration();

/* Load a configuration */
void load_configuration(Configuration *_config, char *_path);

#endif 

