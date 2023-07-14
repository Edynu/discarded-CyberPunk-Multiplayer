
#include "yojimbo.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include <time.h>

using namespace yojimbo;
enum class GameMessageType {
    TEST,
    COUNT
};

// two channels, one for each type that Yojimbo supports
enum class GameChannel {
    RELIABLE,
    UNRELIABLE,
    COUNT
};

// the client and server config
struct GameConnectionConfig : yojimbo::ClientServerConfig {
    GameConnectionConfig() {
        numChannels = 2;
        channel[(int)GameChannel::RELIABLE].type = yojimbo::CHANNEL_TYPE_RELIABLE_ORDERED;
        channel[(int)GameChannel::UNRELIABLE].type = yojimbo::CHANNEL_TYPE_UNRELIABLE_UNORDERED;
    }
};

// the adapter

class GameServer {
public:

    GameServer::GameServer(const yojimbo::Address& address);

private:
    GameAdapter* m_adapter;
    GameServer* m_server;

};

class GameAdapter : public yojimbo::Adapter {
public:
    explicit GameAdapter(GameServer* server = NULL) :
        m_server(server) {}

    yojimbo::MessageFactory* CreateMessageFactory(yojimbo::Allocator& allocator) override {
        return YOJIMBO_NEW(allocator, GameMessageFactory, allocator);
    }

    void OnServerClientConnected(int clientIndex) override {
        if (m_server != NULL) {
            m_server->ClientConnected(clientIndex);
        }
    }

    void OnServerClientDisconnected(int clientIndex) override {
        if (m_server != NULL) {
            m_server->ClientDisconnected(clientIndex);
        }
    }

private:
    GameServer* m_server;
};

// the message factory
YOJIMBO_MESSAGE_FACTORY_START(GameMessageFactory, (int)GameMessageType::COUNT);
YOJIMBO_DECLARE_MESSAGE_TYPE((int)GameMessageType::TEST, TestMessage);
YOJIMBO_MESSAGE_FACTORY_FINISH();

class TestMessage : public yojimbo::Message {
public:
    int m_data;

    TestMessage() :
        m_data(0) {}

    template <typename Stream>
    bool Serialize(Stream& stream) {
        serialize_int(stream, m_data, 0, 512);
        return true;
    }

    YOJIMBO_VIRTUAL_SERIALIZE_FUNCTIONS();
};