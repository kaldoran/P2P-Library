#include <stdlib.h>
#include <stdio.h>
#include "p2p.h"

int main(int argc, char *argv[]) {
    bool connected = FALSE;

    if ( (connected = connection()) == FALSE ) 
        return(EXIT_FAILURE);

    // PLAY GAME
        // tcp_send("Salu2", 6);
        // tcp_recv(buffer, sizeof(buffer));
    // END GAME

    if ( connected ) 
        (void) disconnect();
    
    return(EXIT_SUCCESS);
}
