#include <iostream>
#include "boost/asio.hpp"
#include <string>

using namespace boost::asio;
using namespace boost::asio::ip;

int main() {
    io_service io;

    // Create a TCP socket
    tcp::socket sock(io);

    // Bind the socket to a port
    endpoint endpoint(tcp::v4(), 8080);
    sock.bind(endpoint);

    // Listen for incoming connections
    sock.listen();

    std::cout << "Server started. Waiting for incoming connections..." << std::endl;

    while (true) {
        // Accept an incoming connection
        tcp::socket new_sock = sock.accept();

        // Handle the incoming connection
        std::cout << "New connection accepted." << std::endl;

        // Read data from the client
        char buffer[1024];
        size_t bytes_received = read(new_sock, buffer, 1024);

        // Process the received data
        std::string received_data(buffer, bytes_received);
        std::cout << "Received data: " << received_data << std::endl;

        // Send a response back to the client
        std::string response = "Hello, client!";
        write(new_sock, buffer, response.size());
    }

    return 0;
}