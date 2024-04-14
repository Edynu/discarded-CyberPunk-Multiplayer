#pragma once
#include <RED4ext/Scripting/Natives/Generated/ent/EntityID.hpp>

struct ccPlayer
{
    int m_id = 0;
    int m_health = 0;
    int m_x = 0;
    int m_y = 0;
    int m_z = 0;
    float m_i = 0;
    float m_j = 0;
    float m_k = 0;
    float m_r = 0;
    bool m_isDead = false;
    bool m_isConnected = false;
    int entityId = 0;
    RED4ext::EntityID entity_id;
};

inline ccPlayer onlinePlayers[64];

class CCConnect
{
public:
    static void StartConnection(const std::wstring& ip, const std::wstring& port);

private:
    CCConnect* cc_net;
};
