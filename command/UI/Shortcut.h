#ifndef SHORTCUT_H_
#define SHORTCUT_H_
#include<memory>
namespace cmd
{
	class Command;
}
namespace ui
{
	class Shortcut
	{
	public:
		Shortcut(std::shared_ptr<cmd::Command> command) :command(command) {}
		std::shared_ptr<cmd::Command> getCommand() { return command; }
		bool key();
	private:
		std::shared_ptr<cmd::Command> command;
	};
}
#endif // !_SHORTCUT_H_
