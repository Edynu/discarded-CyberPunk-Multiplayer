/*
    Yojimbo Client Example (insecure)

    Copyright © 2016 - 2019, The Network Protocol Company, Inc.

    Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

        1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.

        2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer 
           in the documentation and/or other materials provided with the distribution.

        3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived 
           from this software without specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, 
    INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE 
    DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
    SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR 
    SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, 
    WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE
    USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include "yojimbo.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include <time.h>
#include <signal.h>
#include "shared.h"
#include "Networking.h"

using namespace yojimbo;

static volatile int quit = 0;

void interrupt_handler( int /*dummy*/ )
{
    quit = 1;
}

void ClientMain( int argc)
{   
    printf( "\nconnecting client (insecure)\n" );

    double time = 100.0;

    uint64_t clientId = 0;
    random_bytes( (uint8_t*) &clientId, 8 );
    printf( "client id is %.16" PRIx64 "\n", clientId );

    ClientServerConfig config;

    Client client( GetDefaultAllocator(), Address("0.0.0.0"), config, adapter, time );

    Address serverAddress( "127.0.0.1", 40000);

    uint8_t privateKey[KeyBytes];
    memset( privateKey, 0, KeyBytes );

    client.InsecureConnect( privateKey, clientId, serverAddress );

    char addressString[256];
    client.GetAddress().ToString( addressString, sizeof( addressString ) );
    printf( "client address is %s\n", addressString );

    const double deltaTime = 0.01f;

    signal( SIGINT, interrupt_handler );

    while ( !quit )
    {
        //client.SendPackets();

        client.ReceivePackets();
        client.AdvanceTime(client.GetTime() + deltaTime);

        if (client.IsConnected()) {
            ProcessMessages();

            // ... do connected stuff ...

            // send a message when space is presse
        }

        client.SendPackets();
    }

    client.Disconnect();

    return 0;
}

void ProcessMessages() {
    double time = 100.0;
    ClientServerConfig config;
    Client client(GetDefaultAllocator(), Address("0.0.0.0"), config, adapter, time);

    for (int i = 0; i < config.numChannels; i++) {
        yojimbo::Message* message = client.ReceiveMessage(i);
        while (message != NULL) {
            ProcessMessage(message);
            client.ReleaseMessage(message);
            message = client.ReceiveMessage(i);
        }
    }
}

void ProcessMessage(yojimbo::Message* message) {
    switch (message->GetType()) {
    case (int)GameMessageType::TEST:
        ProcessTestMessage((TestMessage*)message);
        break;
    default:
        break;
    }
}

void ProcessTestMessage(TestMessage* message) {
    std::cout << "Test message received from server with data " << message->m_data << std::endl;
}

void OnlineGameScreen(const yojimbo::Address& serverAddress) :
    client(yojimbo::GetDefaultAllocator(), yojimbo::Address("0.0.0.0"), m_connectionConfig, m_adapter, 0.0)
{
    uint64_t clientId;
    yojimbo::random_bytes((uint8_t*)&clientId, 8);
    client.InsecureConnect(DEFAULT_PRIVATE_KEY, clientId, m_serverAddress);
}

bool StartNetworking( int argc)
{
    if ( !InitializeYojimbo() )
    {
        cout << "Connection::Connect() > WSAStartup error" << endl;
        return false;
    }

    yojimbo_log_level( YOJIMBO_LOG_LEVEL_INFO );

    srand( (unsigned int) time( NULL ) );

    ClientMain(argc);

    ShutdownYojimbo();
       
    return true;

}
