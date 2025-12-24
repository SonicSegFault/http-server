#include <netinet/in.h>   // sockaddr_in, in_addr, htons()

namespace http {

    class TcpServer{
        public:
            TcpServer(int port);
            ~TcpServer();

        private:
            int server_socket;
            struct sockaddr_in server_address;

            int startServer();
            void closeServer();
    };
} //namespace http
