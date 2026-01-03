#include "http_server_linux.h"

int main() {
    using namespace http;
    
    TcpServer server(8000);

    return 0;
}
