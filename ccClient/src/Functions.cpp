#include <RED4ext/RED4ext.hpp>
#include <RED4ext/Scripting/Natives/Generated/WorldTransform.hpp>
#include <RED4ext/Scripting/Natives/ScriptGameInstance.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/EntityID.hpp>
#include "Functions.h"

RED4ext::WorldTransform CCFunctions::GetPlayerTransform()
{
    auto const rtti = RED4ext::CRTTISystem::Get();
    auto engine = RED4ext::CGameEngine::Get();

    RED4ext::ScriptGameInstance gameInstance;
    RED4ext::WorldTransform playerCoords{};
    RED4ext::Handle<RED4ext::IScriptable> handle;

    RED4ext::ExecuteGlobalFunction("GetPlayer;GameInstance", &handle, gameInstance);

    if (handle)
    {
        auto const playerPuppetCls = rtti->GetClass("PlayerPuppet");
        auto const getWorldPosFunc = playerPuppetCls->GetFunction("GetWorldTransform");

        RED4ext::ExecuteFunction(handle, getWorldPosFunc, &playerCoords);

        return playerCoords;
    }

    return playerCoords;
}

RED4ext::WorldTransform CCFunctions::GetEntityTransform(RED4ext::EntityID entityID)
{
    auto const rtti = RED4ext::CRTTISystem::Get();
    auto engine = RED4ext::CGameEngine::Get();
    RED4ext::ScriptGameInstance gameInstance;
    RED4ext::WorldTransform entityCoords;
    RED4ext::Handle<RED4ext::IScriptable> handle;
    RED4ext::ExecuteGlobalFunction("GetEntity;GameInstance", &handle, gameInstance);
    if (handle)
    {
        auto const entityCls = rtti->GetClass("entEntity");
        auto const getWorldPosFunc = entityCls->GetFunction("GetWorldTransform");
        RED4ext::ExecuteFunction(handle, getWorldPosFunc, &entityCoords);
        return entityCoords;
    }
    return entityCoords;
}

bool CCFunctions::SetEntityTransfrom(RED4ext::EntityID entityID, RED4ext::WorldTransform transform)
{
    auto const rtti = RED4ext::CRTTISystem::Get();
    auto engine = RED4ext::CGameEngine::Get();
    RED4ext::ScriptGameInstance gameInstance;
    RED4ext::Handle<RED4ext::IScriptable> handle;

     RED4ext::ExecuteFunction("ScriptGameInstance", "FindEntityByID", &handle, gameInstance, &entityID);
    if (handle)
    {
        auto const entityCls = rtti->GetClass("entEntity");
        auto const setWorldPosFunc = entityCls->GetFunction("SetWorldTransform");
        RED4ext::ExecuteFunction(handle, setWorldPosFunc, &transform);
        return true;
    }
    return false;
}

RED4ext::EntityID CCFunctions::SpawnPlayer(int playerSlot, RED4ext::WorldTransform transform)
{
    RED4ext::TweakDBID tweak(0x0454DA27, 0x22);

    RED4ext::EntityID entity_id;
    RED4ext::ExecuteFunction("gamePreventionSpawnSystem", "RequestSpawn", &entity_id, tweak, playerSlot, transform);
    return entity_id;
}

PlayerPosition CCFunctions::GetLocation()
{
    PlayerPosition position;
    RED4ext::WorldTransform newPosition = GetPlayerTransform();
    position.m_id = 0;
    position.m_x = newPosition.Position.x.Bits;
    position.m_y = newPosition.Position.y.Bits;
    position.m_z = newPosition.Position.z.Bits;
    position.m_i = newPosition.Orientation.i;
    position.m_j = newPosition.Orientation.j;
    position.m_k = newPosition.Orientation.k;
    position.m_r = newPosition.Orientation.r;

    return position;
}
