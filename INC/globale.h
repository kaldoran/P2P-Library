//----------------------------------------------------------
// AUTEUR : REYNAUD Nicolas                                 |
// FICHIER : affiche.h                                      |
//----------------------------------------------------------


#ifndef GLOBAL_H
#define GLOBAL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QUIT_MSG(MSG, ...)                      \
do {                                            \
	fprintf(stderr, MSG, ## __VA_ARGS__);       \
	exit(EXIT_FAILURE);                         \
}while(0);

#ifdef DEBUG
	#define DEBUG_PRINTF(MSG, ...)                                                                                                               \
		do {                                                                                                                                     \
			fprintf(stderr, "File : %s - Line : %d - Function : %s() : " MSG, __FILE__, __LINE__, __func__, ## __VA_ARGS__);                     \
		} while(0);
#else
	#define DEBUG_PRINTF(MSG, ...)
#endif

#endif /* GLOBAL_H inclu */



