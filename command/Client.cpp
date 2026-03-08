#include"Application.h"
int main()
{
	auto app = std::make_shared<app::Application>();
	app->init();
	app->run();
	return 0;
}