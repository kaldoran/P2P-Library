//----------------------------------------------------------
// AUTEUR : REYNAUD Nicolas                                 |
// FICHIER : boolean.h                                      |
//----------------------------------------------------------

#ifndef BOOLEAN_H
#define BOOLEAN_H

#ifndef FALSE
    #define FALSE 0
#endif

#ifndef TRUE 
    #define TRUE !FALSE /* True is the invert of False */
#endif

/** Define what is a boolean
 *  'false' is equal to 0 by default.
 */
typedef enum {
    false = 0,
    true
} bool;

#endif /* BOOLEAN_H included */
