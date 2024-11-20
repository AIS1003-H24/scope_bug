#include <iostream>
#include <vector>

#include <simple_socket/TCPSocket.hpp>

using namespace simple_socket;

std::unique_ptr<SimpleConnection> createConnection(int port) {
    TCPServer server(port);
    std::cout << "Waiting for connection..." << std::endl;
    auto conn = server.accept();
    std::cout << "Connection established!" << std::endl;
    return conn;
}

int main() {
    const auto connection = createConnection(9090);

    std::vector<uint8_t> buffer;
    const int read = connection->read(buffer);

    std::cout << "Got: " << read << " bytes" << std::endl;

    std::string data(buffer.begin(), buffer.begin() + read);
    std::cout << "Received data: " << data << std::endl;

    return 0;
}
