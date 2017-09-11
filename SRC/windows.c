//----------------------------------------------------------
// AUTEUR : REYNAUD Nicolas                                 |
// FICHIER : windows.c                                      |
//----------------------------------------------------------

#include "windows.h"
#include "socket.h"
#include "error.h"

void initWindows(void) {
    #ifdef WIN32
       WSADATA wsa;
       if(WSAStartup(MAKEWORD(2, 2), &wsa) < 0) {
          QUIT_MSG("Can't start socket on Windows : ");
       }
    #endif
}

void endWindows(void) {
    #ifdef WIN32
       WSACleanup();
    #endif
}   

