#include "file_handler.h"

int main() {
    Configuration *c = new_configuration();

    load_configuration(&c, "./CONF/config.txt");
}
