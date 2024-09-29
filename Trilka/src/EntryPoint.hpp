#ifndef TK_ENTRYPOINT_HPP
#define TK_ENTRYPOINT_HPP

#include "Application.hpp"
#include "Log.hpp"

extern Trilka::Application* Trilka::CreateApplication();

int main(int argc, char** argv)
{
    Trilka::Log::Init();
    TK_CORE_INFO("Core Info Log!");
    TK_WARN("Warn Log!");
    TK_ERROR("Error Log!");
    TK_TRACE("Trace Log!");

    auto app = Trilka::CreateApplication();
    app->Run();
    delete app;
}

#endif // TK_ENTRYPOINT_HPP
