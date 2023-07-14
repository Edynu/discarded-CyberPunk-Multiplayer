#include <iostream>
#include <ServerNetworking.h>
#include <stdexcept>
#include <string>

static const uint8_t DEFAULT_PRIVATE_KEY[yojimbo::KeyBytes] = { 0 };
static const int MAX_PLAYERS = 64;

GameServer::GameServer(const yojimbo::Address& address) :

    m_adapter(this),
    m_server(yojimbo::GetDefaultAllocator(), DEFAULT_PRIVATE_KEY, Address("127.0.0.1", 40000), m_connectionConfig, m_adapter, 0.0)
{
    // start the server
    m_server.Start(MAX_PLAYERS);
    if (!m_server.IsRunning()) {
        throw std::runtime_error("Could not start server at port " + std::to_string(address.GetPort()));
    }

    // print the port we got in case we used port 0
    char buffer[256];
    m_server.GetAddress().ToString(buffer, sizeof(buffer));
    std::cout << "Server address is " << buffer << std::endl;

    // ... load game ...
}

void GameServer::ClientConnected(int clientIndex) {
    std::cout << "client " << clientIndex << " connected" << std::endl;
}

void GameServer::ClientDisconnected(int clientIndex) {
    std::cout << "client " << clientIndex << " disconnected" << std::endl;
}