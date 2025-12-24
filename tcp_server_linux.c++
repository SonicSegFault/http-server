#include "tcp_server_linux.h"
#include <sys/socket.h>
#include <iostream>
#include <arpa/inet.h>    // inet_pton(), inet_ntop()
#include <unistd.h>

http::TcpServer::TcpServer(int port): server_socket(-1) {
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    server_address.sin_addr.s_addr = INADDR_ANY;

    startServer();
}

http::TcpServer::~TcpServer() { closeServer(); }

int http::TcpServer::startServer() {
    if((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("FD Creation Failed"); return -1;
    }
    //make it reuseable after closing
    int opt = 1;
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0) {
        perror("setsockopt error"); return -1;
    }
    if(bind(server_socket, (const sockaddr*)&server_address, sizeof(server_address)) < 0){
        perror("bind error"); return -1;
    }
    if(listen(server_socket, 5) < 0) {
        perror("Server not listening"); return -1;
    }

    return 0;
}

void http::TcpServer::closeServer() { 
    if (server_socket >= 0) {
        close(server_socket);
        server_socket = -1;
    }
}