#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <cstdint>
#include <stdexcept>
#include <cstring>
#include <unistd.h>
#include <iostream>

class UDPSocket {
  public:
    UDPSocket(uint16_t port) {
        socket_ = socket(AF_INET, SOCK_DGRAM, 0);
        if (socket_ == -1) {
            throw std::runtime_error(strerror(errno));
        }
        sockaddr_in addr;
        memset(&addr, 0, sizeof(addr));
        addr.sin_family = AF_INET;
        addr.sin_port = htons(port);
        addr.sin_addr.s_addr = INADDR_ANY;
        if (bind(socket_, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
            throw std::runtime_error(strerror(errno));
        }
    }

    ~UDPSocket() {
        close(socket_);
    }

    void Send(size_t ip, uint16_t port, const std::string &data) {
        struct sockaddr_in addr;
        memset(&addr, 0, sizeof(addr));
        addr.sin_family = AF_INET;
        addr.sin_port = htons(port);
        addr.sin_addr.s_addr = htonl(ip);
        if (sendto(socket_, data.c_str(), data.size(), 0, (struct sockaddr *) &addr, sizeof(addr)) == -1) {
            throw std::runtime_error(strerror(errno));
        }
    }

    bool Recieve(size_t *ip, uint16_t *port, std::string *data) {
        struct sockaddr_in addr;
        socklen_t addrlen;

        int data_size = recvfrom(socket_, buffer, MAX_MESSAGE_SIZE, 0, (struct sockaddr *) &addr, &addrlen);
        if (data_size == -1) {
            throw std::runtime_error(strerror(errno));
        }
        *ip = addr.sin_addr.s_addr;
        *port = addr.sin_port;
        *data = std::string(buffer, data_size);
        return true;
    }
  private:
    static const size_t MAX_MESSAGE_SIZE = 1024;
    int socket_;
    char buffer[MAX_MESSAGE_SIZE];
};

int main() {
    UDPSocket client(5050);
    client.Send((170524673), 5050, "google loh");
    size_t ip;
    uint16_t port;
    std::string data;
    client.Recieve(&ip, &port, &data);
    std::cout << data << std::endl;
}
