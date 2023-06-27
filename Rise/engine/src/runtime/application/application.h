#pragma once

namespace Rise
{
    class Application
    {
    public:
        Application();
        virtual ~Application() = default;
        void Run();

    private:
        static Application* s_Instance;
    };

    // user difine
    Application* CreateApplication();
} // namespace Rise
