#include <RED4ext/RED4ext.hpp>
#include "Networking.h"
////////////////////////////////////////////////////////
struct MyCustomClass : RED4ext::IScriptable {
	RED4ext::CClass* GetNativeType();
};

RED4ext::TTypedClass<MyCustomClass> cls("MyCustomClass");

RED4ext::CClass* MyCustomClass::GetNativeType() {
	return &cls;
}

void GetNumber(RED4ext::IScriptable* aContext, RED4ext::CStackFrame* aFrame, float* aOut, int64_t a4) {
	aFrame->code++; // skip ParamEnd
	*aOut = 6.25;
}
////////////////////////////////////////////////////////

//Connection Connection;

void ConnectionIsConnected(RED4ext::IScriptable* aContext, RED4ext::CStackFrame* aFrame, bool* aOut, int64_t a4) {
	*aOut = 6.25;
}

void ConnectionConnect(RED4ext::IScriptable* aContext, RED4ext::CStackFrame* aFrame, bool* aOut, int64_t a4) {
	RED4ext::CString ip;
	int port;
	RED4ext::GetParameter(aFrame, &ip);
	RED4ext::GetParameter(aFrame, &port);
	cout << "Start initialization of networking" << endl;
	bool started = StartNetworking(1);
	*aOut = 6.25;
}

void ConnectionDisconnect(RED4ext::IScriptable* aContext, RED4ext::CStackFrame* aFrame, bool* aOut, int64_t a4) {
	*aOut = 6.25;
}

void ConnectionSend(RED4ext::IScriptable* aContext, RED4ext::CStackFrame* aFrame, bool* aOut, int64_t a4) { // Posílání packetu
	RED4ext::CString message;
	RED4ext::GetParameter(aFrame, &message);
	*aOut = 6.25;
}

void ConnectionReceive(RED4ext::IScriptable* aContext, RED4ext::CStackFrame* aFrame, RED4ext::CString* aOut, int64_t a4) {
	*aOut = "6.25";
}

RED4EXT_C_EXPORT void RED4EXT_CALL RegisterTypes() {
	cls.flags = { .isNative = true };
	RED4ext::CRTTISystem::Get()->RegisterType(&cls);
}

RED4EXT_C_EXPORT void RED4EXT_CALL PostRegisterTypes() {
	{
		auto rtti = RED4ext::CRTTISystem::Get();
		auto scriptable = rtti->GetClass("IScriptable");
		cls.parent = scriptable;

		RED4ext::CBaseFunction::Flags flags = { .isNative = true };
		auto getNumber = RED4ext::CClassFunction::Create(&cls, "GetNumber", "GetNumber", &GetNumber);
		getNumber->flags = flags;
		getNumber->SetReturnType("Float");
		cls.RegisterFunction(getNumber);
	}

	auto rtti = RED4ext::CRTTISystem::Get();
	RED4ext::CBaseFunction::Flags flags = { .isNative = true, .isStatic = true };

	{
		auto func = RED4ext::CGlobalFunction::Create("ConnectionIsConnected", "ConnectionIsConnected", &ConnectionIsConnected);
		func->flags = flags;
		func->SetReturnType("Bool");
		rtti->RegisterFunction(func);
	}
	{
		auto func = RED4ext::CGlobalFunction::Create("ConnectionConnect", "ConnectionConnect", &ConnectionConnect);
		func->flags = flags;
		func->AddParam("String", "ip");
		func->AddParam("Int32", "port");
		func->SetReturnType("Bool");
		rtti->RegisterFunction(func);
	}
	{
		auto func = RED4ext::CGlobalFunction::Create("ConnectionDisconnect", "ConnectionDisconnect", &ConnectionDisconnect);
		func->flags = flags;
		func->SetReturnType("Bool");
		rtti->RegisterFunction(func);
	}
	{
		auto func = RED4ext::CGlobalFunction::Create("ConnectionSend", "ConnectionSend", &ConnectionSend);
		func->flags = flags;
		func->AddParam("String", "message");
		func->SetReturnType("Bool");
		rtti->RegisterFunction(func);
	}
	{
		auto func = RED4ext::CGlobalFunction::Create("ConnectionReceive", "ConnectionReceive", &ConnectionReceive);
		func->flags = flags;
		func->SetReturnType("String");
		rtti->RegisterFunction(func);
	}
}

RED4EXT_C_EXPORT bool RED4EXT_CALL Main(RED4ext::PluginHandle aHandle, RED4ext::EMainReason aReason, const RED4ext::Sdk* aSdk) {
	if (aReason == RED4ext::EMainReason::Load) {
		RED4ext::RTTIRegistrator::Add(RegisterTypes, PostRegisterTypes);
	}
	return true;
}

RED4EXT_C_EXPORT void RED4EXT_CALL Query(RED4ext::PluginInfo* aInfo) {
	aInfo->name = L"CyberConnect";
	aInfo->author = L"Edynu, Tayfun";
	aInfo->version = RED4EXT_SEMVER(1, 0, 0);
	aInfo->runtime = RED4EXT_RUNTIME_LATEST;
	aInfo->sdk = RED4EXT_SDK_LATEST;
}

RED4EXT_C_EXPORT uint32_t RED4EXT_CALL Supports() { return RED4EXT_API_VERSION_LATEST; }