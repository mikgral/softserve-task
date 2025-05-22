#include <iostream>
#include "handler.hpp"

using boost::asio::ip::tcp;

void handle_client(tcp::socket& socket) {
    try {
        char data[1024];
        boost::system::error_code error;

        size_t length = socket.read_some(boost::asio::buffer(data), error);
        if (error == boost::asio::error::eof) {
            return; // Connection closed cleanly by peer.
        } else if (error) {
            throw boost::system::system_error(error); // Some other error.
        }

        std::string message(data, length);
        std::cout << "Received: " << message << std::endl;

        std::string msg_to_response = "ping";
        if (message.compare(0, msg_to_response.length(), msg_to_response) == 0) {
            std::string pong = "pong\n";
            boost::asio::write(socket, boost::asio::buffer(pong), error);
            std::cout << "Sent: pong" << std::endl;
        }
    } catch (std::exception& e) {
        std::cerr << "Exception in handle_client: " << e.what() << "\n";
    }
}
