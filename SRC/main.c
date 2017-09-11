#include "windows.h"
#include "boolean.h"
#include "tcp.h"
#include "file_handler.h"
#include "verification.h"

int main() {

    /* Function startP2P(char *filename) */
    char *file_path = "./CONF/config.txt"; 

    initWindows(); // Init socket windows
    Client c;
    Configuration conf; // Create a structure that will contains configuration

    if ( file_exist(file_path) == FALSE )
        QUIT_MSG("File does not exist\n");

    load_configuration(&conf, file_path); // Load the configuration
    c = (Client) conf; // Lets make the conf became a Client 
        
    if ( tcp_start(&c) == FALSE )
        QUIT_MSG("Impossible to connect to [%s:%d] : ", c.ip_addr, c.port);
    
    /* End function */

    tcp_send(c, "Salut", 6);

    /* Function stopP2P */
    (void) tcp_stop(&c);

    endWindows(); // End socket windows
    return(EXIT_SUCCESS);
}
