#include "PipeLine.h"
#include "Networking.h"

#include <iostream>
#include <thread>

void NamedPipeServer::HandleNamedPipeCommunication()
{
    std::wstring pipeName = L"\\\\.\\pipe\\CyberConnectPipe";

    HANDLE pipeHandle = CreateNamedPipe(pipeName.c_str(),           // Pipe name
                                        PIPE_ACCESS_DUPLEX,         // Pipe open mode
                                        PIPE_TYPE_MESSAGE |         // Message-type pipe
                                            PIPE_READMODE_MESSAGE | // Message-read mode
                                            PIPE_WAIT,              // Blocking mode
                                        PIPE_UNLIMITED_INSTANCES,   // Max. instances
                                        4096,                       // Output buffer size
                                        4096,                       // Input buffer size
                                        NMPWAIT_USE_DEFAULT_WAIT,   // Default timeout
                                        nullptr);                   // Security attributes

    if (pipeHandle == INVALID_HANDLE_VALUE)
    {
        throw std::runtime_error("Failed to create named pipe");
    }

    while (true)
    {
        if (ConnectNamedPipe(pipeHandle, nullptr))
        {
            // Once a client is connected, receive a message from the client
            wchar_t buffer[4096];
            DWORD bytesRead;
            if (ReadFile(pipeHandle, buffer, sizeof(buffer), &bytesRead, nullptr))
            {
                // Convert received message to std::wstring
                std::wstring receivedMessage(buffer, bytesRead / sizeof(wchar_t));
                // Process the received message to extract IP and port
                // For example, you can split the received message by ':' character
                size_t pos = receivedMessage.find(L':');
                if (pos != std::wstring::npos && pos < receivedMessage.length() - 1)
                {
                    std::wstring ip = receivedMessage.substr(0, pos);
                    std::wstring port = receivedMessage.substr(pos + 1);

                    std::wcout << L"Received IP: " << ip << L", Port: " << port << std::endl;

                    CCConnect::StartConnection(ip, port);
                }

                std::wstring responseMessage = L"Message received successfully";
                DWORD bytesWritten;
                WriteFile(pipeHandle, responseMessage.c_str(), responseMessage.size() * sizeof(wchar_t), &bytesWritten,
                          nullptr);

                DisconnectNamedPipe(pipeHandle);
            }
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    CloseHandle(pipeHandle);
}
