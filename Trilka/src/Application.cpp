#include "Application.hpp"
#include "Events/ApplicationEvent.hpp"
#include "Log.hpp"

namespace Trilka
{
    Application::Application()
    {
    }

    Application::~Application()
    {
    }

    void Application::Run()
    {
        WindowResizeEvent e(1280, 720);
        if (e.IsInCategory(EventCategoryApplication))
        {
            TK_CORE_TRACE(e);
        }

        while (true);
    }
}
