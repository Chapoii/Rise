#include "engine.h"

class Sandbox : public Rise::Application
{
public:
    Sandbox() {}
    ~Sandbox() {}
};

Rise::Application* Rise::CreateApplication() { return new Sandbox(); }
