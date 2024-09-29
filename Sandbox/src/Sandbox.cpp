#include <Trilka.hpp>

class Sandbox : public Trilka::Application
{
public:
    Sandbox()
    {
    }

    ~Sandbox()
    {
    }
};

Trilka::Application* Trilka::CreateApplication()
{
    return new Sandbox();
}
