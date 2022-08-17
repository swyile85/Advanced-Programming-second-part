#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include "FilesFunc.hpp"
#include "Iris.hpp"

using namespace std;

int main(int argc, char** argv) {

    const char* ip_address = "127.0.0.1";
    const int port_no = 5555;

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) { perror("error creating socket"); }

    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr(ip_address);
    sin.sin_port = htons(port_no);

    if (connect(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("error connecting to server");
    }

    char data_addr[] = fileToString(argv[0]);
    int data_len = strlen(data_addr);
    int sent_bytes = send(sock, data_addr, data_len, 0);

    if (sent_bytes < 0) {
        perror("error");
    }

    char buffer[4096];
    int expected_data_len = sizeof(buffer);
    int read_bytes = recv(sock, buffer, expected_data_len, 0);
    if (read_bytes == 0) {
        perror("error");
    }
    else if (read_bytes < 0) {
        perror("error");
    }
    else {
        typesToFile(buffer, argv[1], readFile(argv[0]));
    }

    close(sock);


    return 0;
}