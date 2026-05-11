#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <vector>
#include <string>

bool is_port_open(const std::string& ip, int port) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) return false;

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    inet_pton(AF_INET, ip.c_str(), &addr.sin_addr);

    struct timeval tv;
    tv.tv_sec = 0;
    tv.tv_usec = 500000;
    setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, (const char*)&tv, sizeof(tv));

    bool open = (connect(sock, (struct sockaddr*)&addr, sizeof(addr)) == 0);
    close(sock);
    return open;
}

int main() {
    std::string target = "127.0.0.1";
    std::vector<int> common_ports = {21, 22, 53, 80, 443, 3000, 8080};

    std::cout << "--- [ Port Security Audit ] ---" << std::endl;
    std::cout << "Target: " << target << "\n" << std::endl;

    for (int port : common_ports) {
        std::cout << "[ CHECK ] Port " << port << "... ";
        if (is_port_open(target, port)) {
            std::cout << "\033[1;31mOPEN\033[0m" << std::endl;
        } else {
            std::cout << "\033[1;32mCLOSED\033[0m" << std::endl;
        }
    }

    std::cout << "\nAudit complete. Signed by Storm." << std::endl;
    return 0;
}
