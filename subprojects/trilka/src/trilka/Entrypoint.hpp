#ifndef TK_ENTRYPOINT_HPP
#define TK_ENTRYPOINT_HPP

#include "Application.hpp"

extern Trilka::Application* Trilka::CreateApplication();

int main(int argc, char** argv)
{
    auto app = Trilka::CreateApplication();
    app->Run();
    delete app;
}

#endif // TK_ENTRYPOINT_HPP
