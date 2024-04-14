#include <RED4ext/RED4ext.hpp>
#include <RED4ext/Scripting/Natives/Generated/WorldTransform.hpp>
#include <RED4ext/Scripting/Natives/ScriptGameInstance.hpp>

#include <chrono> // For std::chrono
#include <iostream>
#include <string>
#include <thread> // For std::thread
#include <windows.h>
#include "PipeLine.h"



RED4EXT_C_EXPORT bool RED4EXT_CALL Main(RED4ext::PluginHandle aHandle, RED4ext::EMainReason aReason,
                                        const RED4ext::Sdk* aSdk)
{
    switch (aReason)
    {
    case RED4ext::EMainReason::Load:
    {
        std::wstring pipeName = L"\\\\.\\pipe\\CyberConnectPipe";


        // Start a new thread to handle named pipe communication between launcher and plugin
        NamedPipeServer pipeServer; // Create an instance of NamedPipeServer
        std::thread t(&NamedPipeServer::HandleNamedPipeCommunication, &pipeServer);
        t.detach();

        break;
    }
    case RED4ext::EMainReason::Unload:
    {
        /*
         * Here you can free resources you allocated during initalization or during the time your plugin was executed.
         */
        break;
    }
    }

    /*
     * For more information about this function see https://docs.red4ext.com/mod-developers/creating-a-plugin#main.
     */

    return true;
}

RED4EXT_C_EXPORT void RED4EXT_CALL Query(RED4ext::PluginInfo* aInfo)
{
    aInfo->name = L"CyberConnect";
    aInfo->author = L"Edynu";
    aInfo->version = RED4EXT_SEMVER(1, 0, 0);
    aInfo->runtime = RED4EXT_RUNTIME_LATEST;
    aInfo->sdk = RED4EXT_SDK_LATEST;
}

RED4EXT_C_EXPORT uint32_t RED4EXT_CALL Supports()
{
    /*
     * This functions returns only what API version is support by your plugins.
     * You MUST have this function!
     *
     * For more information about this function see https://docs.red4ext.com/mod-developers/creating-a-plugin#supports.
     */
    return RED4EXT_API_VERSION_LATEST;
}
