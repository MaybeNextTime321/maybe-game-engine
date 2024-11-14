#include <Maybe.h>
#include "mbpch.h"

class Sandbox : public Maybe::Application
{
  public:
    Sandbox()
    {
    }

    virtual ~Sandbox()
    {
    }
};

Maybe::Application *CreateApplication()
{
    MB_LOG_ERROR("Client error");
    return new Sandbox();
}