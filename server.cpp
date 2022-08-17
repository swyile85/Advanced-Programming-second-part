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
 * @brief The main is responsible for the server operation.
 * 
 * @return int The return value.
 */
int main() {
    cout << "SERVER" << endl;
    string classifiedFile = "classified.csv";
    // The path to the data about the classified irises.
    Iris* classified = readFile(classifiedFile);
    int numOfClassified = lengthOfFile(classifiedFile);
    const int server_port = 5555;

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("error creating socket");
    }

    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(server_port);

    if (bind(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("error binding socket");
    }
    
    if (listen(sock, 5) < 0) {
        perror("error listening to a socket");
    }

    struct sockaddr_in client_sin;
    unsigned int addr_len = sizeof(client_sin);
    int client_sock = accept(sock,  (struct sockaddr *) &client_sin,  &addr_len);

    if (client_sock < 0) {
        perror("error accepting client");
    }

    char buffer[4096];
    int expected_data_len = sizeof(buffer);
    int read_bytes = recv(client_sock, buffer, expected_data_len, 0);
    string types = "";
    if (read_bytes == 0) {
        close(client_sock);
    }
    else if (read_bytes < 0) {
        perror("error");
    }
    else {
        // creating a string of types based on classified.
        cout << "Classify..." << endl;
        int counter;
        Iris* unClassified = Iris::stringToIrises(string(buffer), counter);
        for (int i = 0; i < counter; i++) {
            types += unClassified[i].classify(classified, 5, numOfClassified,
            &Iris::euclideanDistance);
            types += " ";
        }
        delete[] unClassified;
        cout << "classified successfully!" << endl;
    }
    int length = types.length();
    int sent_bytes = send(client_sock, types.c_str(), length, 0);
    cout << "sent it back to the client" << endl;
    if (sent_bytes < 0) {
        perror("error sending to client");
    }

    delete[] classified;

    close(sock);


    return 0;
}