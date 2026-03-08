#ifndef COMMAND_H_
#define COMMAND_H_
#include<memory>
namespace app {
	class Application;
}
namespace cmd
{
	class Command
	{
	public:
		Command(std::shared_ptr<app::Application> app) :app(app) {}
		virtual std::shared_ptr<Command> clone() = 0;
		virtual bool execute() = 0;
		virtual void undo() {}
		virtual void redo() { (void)this->execute(); }
		virtual ~Command() = default;
	protected:
		//对应应用程序
		std::weak_ptr<app::Application> app;
	};
}
#endif
