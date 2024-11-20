#include <iostream>
#include <vector>

#include <simple_socket/TCPSocket.hpp>

using namespace simple_socket;

int main() {
    TCPServer server(9090);

    std::cout << "Waiting for connection..." << std::endl;
    const auto connection = server.accept();
    std::cout << "Connection accepted" << std::endl;

    std::vector<uint8_t> buffer(1024);
    const int read = connection->read(buffer);

    std::cout << "Got: " << read << " bytes" << std::endl;

    std::string data(buffer.begin(), buffer.begin() + read);
    std::cout << "Received data: " << data << std::endl;

    return 0;
}
