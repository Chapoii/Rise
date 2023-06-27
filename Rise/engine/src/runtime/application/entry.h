// 入口点
#pragma once
#include "application/application.h"

#ifdef RS_PLATFORM_WINDOWS

extern Rise::Application* Rise::CreateApplication();

int main(int argc, char** argv)
{
    Rise::Log::Init();
    RS_CORE_INFO("INIT LOG.");
    auto app = Rise::CreateApplication();
    RS_CORE_INFO("APP CREATED.");
    app->Run();
    delete app;
    RS_CORE_INFO("APP DELETED.");
    return 0;
}

#endif
