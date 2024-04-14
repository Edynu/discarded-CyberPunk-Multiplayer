/*
    Yojimbo Client Example (insecure)

    Copyright © 2016 - 2019, The Network Protocol Company, Inc.

    Redistribution and use in source and binary forms, with or without modification, are permitted provided that the
   following conditions are met:

        1. Redistributions of source code must retain the above copyright notice, this list of conditions and the
   following disclaimer.

        2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the
   following disclaimer in the documentation and/or other materials provided with the distribution.

        3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote
   products derived from this software without specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
    INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
    DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
    SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
    SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
    WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE
    USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include "shared.h"
#include "yojimbo.h"
#include <inttypes.h>
#include <signal.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <random>
#include "Networking.h"
#include <string>
#include <iostream>
#include "Game.h"

using namespace yojimbo;

static volatile int quit = 0;

void random_bytes(uint8_t* buffer, size_t length)
{
    // Seed the random number generator
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Generate random bytes
    for (size_t i = 0; i < length; ++i)
    {
        buffer[i] = static_cast<uint8_t>(std::rand() % 256);
    }
}

void interrupt_handler(int /*dummy*/)
{
    quit = 1;
}

int ClientMain(int argc, char* argv[])
{
    printf("\nconnecting client (insecure)\n");

    double time = 100.0;

    uint64_t clientId = 0;
    random_bytes((uint8_t*)&clientId, 8);
    printf("client id is %.16" PRIx64 "\n", clientId);

    ClientServerConfig config;

    Client client(GetDefaultAllocator(), Address("0.0.0.0"), config, adapter, time);

    Address serverAddress("127.0.0.1", ServerPort);

    if (argc >= 1) // Ensure at least IP and port are provided as arguments
    {
        // Set server address using provided IP and port
        //print to console the ip and port
        serverAddress = Address(argv[0], atoi(argv[1]));
    }
    

    uint8_t privateKey[KeyBytes];
    memset(privateKey, 0, KeyBytes);

    client.InsecureConnect(privateKey, clientId, serverAddress);

    char addressString[256];
    client.GetAddress().ToString(addressString, sizeof(addressString));
    printf("client address is %s\n", addressString);

    const double deltaTime = 0.01f;

    signal(SIGINT, interrupt_handler);

    CCGame game;

    game.StartGame();

    while (!quit)
    {
        client.SendPackets();

        client.ReceivePackets();

        if (client.IsDisconnected())
            break;

        time += deltaTime;

        client.AdvanceTime(time);

        if (client.ConnectionFailed())
            break;

        yojimbo_sleep(deltaTime);
    }

    client.Disconnect();

    return 0;
}

int main(int argc, char* argv[])
{
    if (!InitializeYojimbo())
    {
        printf("error: failed to initialize Yojimbo!\n");
        return 1;
    }

    yojimbo_log_level(YOJIMBO_LOG_LEVEL_INFO);

    srand((unsigned int)time(NULL));

    int result = ClientMain(argc, argv);

    ShutdownYojimbo();

    printf("\n");

    return result;
}

void CCConnect::StartConnection(const std::wstring& ip, const std::wstring& port)
{
    // Convert wide strings to multibyte strings
    std::vector<char> ipMultiByte(ip.size() + 1);
    std::vector<char> portMultiByte(port.size() + 1);
    wcstombs(ipMultiByte.data(), ip.c_str(), ip.size() + 1);
    wcstombs(portMultiByte.data(), port.c_str(), port.size() + 1);

    // Start the connection
    main(3, new char*[3] { ipMultiByte.data(), portMultiByte.data() });
}
