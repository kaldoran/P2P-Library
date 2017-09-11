//----------------------------------------------------------
// AUTEUR : REYNAUD Nicolas                                 |
// FICHIER : error.h                                        |
//                                                          |
// - Debug Maccro [C99 Convention]                          |
// - Quit maccro                                            |
//----------------------------------------------------------

#ifndef ERROR_H
#define ERROR_H

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

/** If we are on windows, as far as consol return directly after quit i had a user input 
 *  With that he can see message before quit
 */
#ifdef WIN32
    #define END()                                                                                               \
        do {                                                                                                    \
            printf("[INFO] Press enter to continue\n");                                                         \
            getchar();                                                                                          \
        } while(0);
#else
    #define END()
#endif

/** If Debug Flag is on, create a maccro to print debug information
 *  %param MSG : String to print 
 *  %param ... : List of param [ for example if want to print variable value ]
 */
#ifdef DEBUG
    #define DEBUG_MSG(MSG, ...)                                                                                                             \
    do {                                                                                                                                    \
        fprintf(stderr, "\n\t[DEBUG] File : %s - Line : %d - Function : %s() : " MSG "\n", __FILE__, __LINE__, __func__, ## __VA_ARGS__);   \
    } while(0);
#else
    #define DEBUG_MSG(MSG, ...)
#endif


/** Create a maccro for quit the program 
 *  %param MSG : String to print 
 *  %param ... : List of param [ for example if want to print variable value ]
 */
#define QUIT_MSG(MSG, ...)                                                                                                  \
    do {                                                                                                                    \
        DEBUG_MSG(MSG, ##__VA_ARGS__)                                                                                       \
        fprintf(stderr, "[FATAL ERROR] ");                                                                                  \
        fprintf(stderr, MSG, ## __VA_ARGS__);                                                                               \
        perror(NULL);                                                                                                       \
        END();                                                                                                              \
        exit(EXIT_FAILURE);                                                                                                 \
    }while(0); 

/** Create a maccro for return FALSE and display ERROR before message 
 *  %param MSG : String to print 
 *  %param ... : List of param [ for example if want to print variable value ]
 */
#define ERROR_MSG(MSG, ...)                                                                                                 \
    do {                                                                                                                    \
        fprintf(stderr, "\t[ERROR] ");                                                                                      \
        fprintf(stderr, MSG, ## __VA_ARGS__);                                                                               \
        return FALSE;                                                                                                       \
    } while(0);

#endif /* ERROR_H included */
