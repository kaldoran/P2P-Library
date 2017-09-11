//----------------------------------------------------------
// AUTEUR : REYNAUD Nicolas                                 |
// FICHIER : socket.h                                       |
//----------------------------------------------------------

#include <unistd.h>

#if defined (WIN32)
    #include <winsock2.h>
#elif defined (linux)

    #include <sys/types.h>
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
    
    #include <netdb.h>

    #define INVALID_SOCKET -1
    #define SOCKET_ERROR -1
    #define closesocket(s) close (s)

    typedef int SOCKET;
    typedef struct sockaddr_in SOCKADDR_IN;
    typedef struct sockaddr SOCKADDR;

#endif
