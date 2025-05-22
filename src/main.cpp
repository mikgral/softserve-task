#include <iostream>
#include "handler.hpp"
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

int main() {
    try {
        boost::asio::io_context io_context;

        tcp::acceptor acceptor(io_context, tcp::endpoint(tcp::v4(), 1234));

        std::cout << "Hello from SoftServe interview app! Connect to app with Telnet and type 'ping'" << std::endl;

        while (true) {
            tcp::socket socket(io_context);
            acceptor.accept(socket);
            handle_client(socket);
        }
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    return 0;
}
