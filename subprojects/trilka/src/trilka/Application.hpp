#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "Core.hpp"

namespace Trilka
{
    class TRILKA_API Application
    {
    public:
        Application();
        virtual ~Application();

        void Run();
    };

    Application* CreateApplication();
}

#endif // APPLICATION_HPP
