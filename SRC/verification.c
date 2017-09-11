//----------------------------------------------------------
// AUTEUR : REYNAUD Nicolas                                 |
// FICHIER : verification.c                                 |
//----------------------------------------------------------

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

#include "error.h"
#include "verification.h"

bool file_exist(const char* _filename) {
    struct stat s;
    
    if ( stat(_filename, &s) == -1 )
        ERROR_MSG("'%s' does not exist.\n", _filename);
    
    if ( s.st_mode & S_IFDIR )
        ERROR_MSG("'%s' is a directory.\n", _filename);

    return TRUE;
}

bool verif_ip(const char* _ip) {
    int total = 0;
    
    char tmp_ip[15];
    char *token;
    int itoken;
   
    strcpy(tmp_ip, _ip);
    token = strtok(tmp_ip, ".");

    while( token != NULL ) {        
        itoken = atoi(token);
        if ( itoken < 0 || itoken > 255 || *_ip == '.' ) 
            ERROR_MSG("Ip range for each part is from 0 To 255\n"); 
        
        if ( (token = strtok(NULL, ".")) == NULL && total == 0 )
            ERROR_MSG("Ip delimitor is '.'\n");

        ++total;
    }
    
    if ( total != 4 ) { 
        ERROR_MSG("Ip is normaly composed by 4 part\n"); 
    }
    
    return TRUE;
}


bool verif_port(int _port) {

    if(_port <= 1024)
        ERROR_MSG("The port must be greater than 1024.\n");

    if(_port > 65536)
        ERROR_MSG("The port must be lower than 65536.\n");

    return TRUE;
}
