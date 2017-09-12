#include "p2p.h"
#include "tcp.h"
#include "error.h"
#include "file_handler.h"
#include "windows.h"
#include "verification.h"

bool connection(const char* filename) {
    initWindows(); // Init socket windows
    Configuration conf; // Create a structure that will contains configuration

    if ( file_exist(filename) == FALSE )
        ERROR_MSG("File does not exist\n");

    load_configuration(&conf, filename); // Load the configuration
    c = (Client) conf; // Lets make the conf became a Client 
        
    if ( tcp_start(&c) == FALSE )
        ERROR_MSG("Impossible to connect to [%s:%d] : ", c.ip_addr, c.port);

    return TRUE;
}

bool disconnect() {
    (void) tcp_stop(&c);

    endWindows(); // End socket windows

    return TRUE;
}
