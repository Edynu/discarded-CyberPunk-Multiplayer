#pragma once

struct PlayerPosition
{
    int m_id = 0;
    int m_x = 0;
    int m_y = 0;
    int m_z = 0;
    float m_i = 0;
    float m_j = 0;
    float m_k = 0;
    float m_r = 0;
    RED4ext::WorldTransform GetPlayerTransform();
};

class CCFunctions
{
    RED4ext::WorldTransform GetPlayerTransform();
    RED4ext::WorldTransform GetEntityTransform(RED4ext::EntityID entityID);
    bool SetEntityTransfrom(RED4ext::EntityID entityID, RED4ext::WorldTransform transform);
    RED4ext::EntityID SpawnPlayer(int playerSlot, RED4ext::WorldTransform transform);
    PlayerPosition GetLocation();
};
