#include <Maybe.h>


class Sandbox : public Maybe::Application
{
public:
	Sandbox() {}
	virtual ~Sandbox(){}
};


Maybe::Application* CreateApplication()
{
	return new Sandbox();
}