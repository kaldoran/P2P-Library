#include <stdlib.h>
#include "p2p.h"

int main() {
    char msg[20];
    if ( connection("./CONF/config.txt") == FALSE ) return(EXIT_FAILURE);

    // PLAY GAME
    tcp_send("Salut", 6);
    tcp_recv(msg, 20);
    // END GAME

    (void) disconnect();
    
    return(EXIT_SUCCESS);
}
