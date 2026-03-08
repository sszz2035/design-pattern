#ifndef BUTTON_H_
#define BUTTON_H_
#include<memory>
namespace cmd
{
	class Command;
}
namespace ui
{
	class Button
	{
	public:
		Button(std::shared_ptr<cmd::Command> command) :command(command) {}
		bool click();
		std::shared_ptr<cmd::Command> getCommand() { return command; }
	private:
		std::shared_ptr<cmd::Command> command;
	};
}
#endif // !_BUTTON_H_
