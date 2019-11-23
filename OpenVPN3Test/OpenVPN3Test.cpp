
#include <iostream>
#include <thread>

#include "TestClient.h"

#define OPENVPN_CORE_API_VISIBILITY_HIDDEN

int main(const int argc, const char** argv)
{
    TestClient client;

    if (client.ApplyConfigFile("vpnbook-fr8-tcp443.ovpn") == false) {
        return -1;
    }


    TestClient::init_process();

    std::thread lThread { [&]() -> void {
        auto lStatus = client.connect();
        std::cout << lStatus.message << std::endl;
    } };

    std::cout << "Press any key to exit!" << std::endl;
    std::cin.get();

    client.stop();
    lThread.join();

    TestClient::uninit_process();
    return 0;
}