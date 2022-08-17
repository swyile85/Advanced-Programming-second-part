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
/**
 * @brief The main function is responsible for the operating of the client.
 * 
 * @param argc The number of arguments.
 * @param argv The arguments.
 * @return int The return value.
 */
int main(int argc, char** argv) {
    cout << "CLIENT" << endl;
    const string inputFile = argv[1], outputFile = argv[2];
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

    string data = fileToString(inputFile);
    int data_len = data.length();
    cout << "sending to the server..." << endl;
    int sent_bytes = send(sock, data.c_str(), data_len, 0);
    cout << "been sent" << endl;
    if (sent_bytes < 0) {
        perror("error");
    }

    char buffer[4096];
    int expected_data_len = sizeof(buffer);
    int read_bytes = recv(sock, buffer, expected_data_len, 0);
    cout << "received it" << endl;
    if (read_bytes == 0) {
        perror("error");
    }
    else if (read_bytes < 0) {
        perror("error");
    }
    else {
        typesToFile(string(buffer), outputFile);
        cout << "thank you" << endl;
    }

    close(sock);

    return 0;
}