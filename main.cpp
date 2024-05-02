#include <iostream>
#include "boost/asio.hpp"
#include <string>
#include "jeu.h"
#include "joueur.h"
#include "pion.h"

using namespace boost::asio;
using namespace boost::asio::ip;
int main()
{
    Jeu J;
    J.demarrer();
    return 0;

    // io_service io;

    // // Create a TCP socket
    // tcp::socket sock(io);

    // // Connect to the server
    // endpoint endpoint(tcp::v4(), 8080);
    // sock.connect(endpoint);

    // std::cout << "Connected to the server." << std::endl;

    // // Send data to the server
    // std::string data = "Hello, server!";
    // write(sock, data);

    // // Read the response from the server
    // char buffer[1024];
    // size_t bytes_received = read(sock, buffer, 1024);

    // // Process the received data
    // std::string received_data(buffer, bytes_received);
    // std::cout << "Received data: " << received_data << std::endl;

    return 0;
}