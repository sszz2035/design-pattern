#ifndef COPYCOMMAND_H_
#define COPYCOMMAND_H_
#include"Command.h"
#include<string>
namespace cmd
{
	class CopyCommand :public Command
	{
	public:
		using Command::Command;
		std::shared_ptr<Command> clone() override;
		bool execute() override;
	};
}
#endif // !_COPYCOMMAND_H_
