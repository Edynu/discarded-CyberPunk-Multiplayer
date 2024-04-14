#include <RED4ext/Relocation.hpp>
#include <RED4ext/Hashing/FNV1a.hpp>
#include <MinHook.h>
#include "Game.h"

using TInitScriptMemberVariable = void*(void* a1, void* a2, uint64_t a3, uint64_t nameHash, void* a5, void* a6,
                                        void* a7);
TInitScriptMemberVariable* RealInitScriptMemberVariable = nullptr;

void* HookInitScriptMemberVariable(void* a1, void* a2, uint64_t a3, uint64_t nameHash, void* a5, void* a6, void* a7)
{
    if (nameHash == RED4ext::FNV1a64("logoTrainWBBink") || nameHash == RED4ext::FNV1a64("logoTrainNamcoBink") ||
        nameHash == RED4ext::FNV1a64("logoTrainStadiaBink") || nameHash == RED4ext::FNV1a64("logoTrainNoRTXBink") ||
        nameHash == RED4ext::FNV1a64("logoTrainRTXBink") || nameHash == RED4ext::FNV1a64("introMessageBink"))
    {
        nameHash = ~nameHash;
    }

    return RealInitScriptMemberVariable(a1, a2, a3, nameHash, a5, a6, a7);
}

void CCGame::StartGame()
{
    const RED4ext::UniversalRelocPtr<void> func(4056423627UL);
    RealInitScriptMemberVariable = reinterpret_cast<TInitScriptMemberVariable*>(func.GetAddr());

    if (RealInitScriptMemberVariable == nullptr)
    {

        return;
    }

    //MH_CreateHook(reinterpret_cast<void*>(RealInitScriptMemberVariable),
    //                  reinterpret_cast<void*>(&HookInitScriptMemberVariable),
    //                  reinterpret_cast<void**>(&RealInitScriptMemberVariable));
}
