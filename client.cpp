#include <chrono>
#include <iostream>
#include <ostream>
#include <thread>
#include <simple_socket/TCPSocket.hpp>

using namespace simple_socket;

int main() {
    TCPClientContext ctx;
    const auto connection = ctx.connect("127.0.0.1", 9090);

    if (connection) {
        connection->write("Hello world!");
        std::cout << "Wrote data to server" << std::endl;
    } else {
        std::cerr << "Connection failed" << std::endl;
    }
}
