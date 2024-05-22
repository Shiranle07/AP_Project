#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <pthread.h>
#include <sstream>
#include "BloomFilter.h"
#include "HashOne.h"
#include "HashTwo.h"
#include "CheckUrlCommand.h"
#include "InputValidation.h"
#include "InsertUrlCommand.h"

const int server_port = 5558;

map<int, IHash*> hashesMap;
IHash* hash1 = new HashOne();
IHash* hash2 = new HashTwo();

ICommand* check = new CheckUrlCommand();
ICommand* insert = new InsertUrlCommand();
map<int, ICommand*> commands;

// creating an empty map to the hash function the user will ask to use with
map<int, bool> hashToRunMap;

InputValidation* checker = NULL;

BloomFilter* bloomFilter = new BloomFilter(hashToRunMap, hashesMap);

bool initialized = false;

void* clientHandler(void* client_socket_ptr) {
    int client_sock = *((int*)client_socket_ptr);
    char buffer[4096];
    int expected_data_len = sizeof(buffer);
    int read_bytes = recv(client_sock, buffer, expected_data_len, 0);
    if (read_bytes == 0) {
        close(client_sock);
    } else if (read_bytes < 0) {
        perror("error reading from client");
    } else {
        std::cout << "Received from client: " << buffer << std::endl;
        string input(buffer);

        // converting the string input to a vector
        istringstream iss(input);
        vector<string> line;
        string word;
        while(iss >> word){
            line.push_back(word);
        }

        string response;

        if (initialized) {
            bool result = checker->checkOtherLines(line);
            if (result) {
                response = "true";
            } else {
                response = "false";
            }
        } else {
            for(auto& pair : hashesMap){
                hashToRunMap[pair.first] = false;
            }
            if(!checker->checkFirstLine(line)){ // if first line is invalid, starts new iteration
                perror("checkFirstLine returned false");
                response = "NOK";
            } else {
                // initilaze bloom filter according to the array size
                bloomFilter->initialize(stoi(line[0]));
                initialized = true;
                response = "OK";
            }
        }

        int sent_bytes = send(client_sock, response.c_str(), response.size(), 0);
        if (sent_bytes < 0) {
            perror("error sending to client");
        }
    }
    close(client_sock);
    return NULL;
}

int main() {
    // initilizing hashes map with the supporting hash function on the program
    hashesMap[1] = hash1;
    hashesMap[2] = hash2;

    // initilizing commands map with the supporting commands on the program
    commands[1] = insert;
    commands[2] = check;

    checker = new InputValidation(commands, hashToRunMap, bloomFilter);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("error creating socket");
        return 1;
    }

    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(server_port);
    if (::bind(sock, (struct sockaddr*)&sin, sizeof(sin)) < 0) {
        perror("error binding socket");
        return 1;
    }

    if (listen(sock, 5) < 0) {
        perror("error listening to a socket");
        return 1;
    }

    while (true) {
        struct sockaddr_in client_sin;
        unsigned int addr_len = sizeof(client_sin);
        int client_sock = accept(sock, (struct sockaddr*)&client_sin, &addr_len);
        if (client_sock < 0) {
            perror("error accepting client");
            continue;
        }
        pthread_t thread_id;
        if (pthread_create(&thread_id, NULL, clientHandler, &client_sock) != 0) {
            perror("error creating thread");
            continue;
        }
        pthread_detach(thread_id);
    }

    close(sock);
    return 0;
}
