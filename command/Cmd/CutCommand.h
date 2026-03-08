#ifndef CUTCOMMAND_H_
#define CUTCOMMAND_H_
#include"Command.h"
#include<string>
namespace cmd
{
	class CutCommand :public Command
	{
	public:
		using Command::Command;
		std::shared_ptr<Command> clone() override;
		bool execute() override;
		void undo() override;
		void redo() override;
	private:
		void saveBackup();
	private:
		//编辑器原来的文本内容
		std::string preText;
		std::string preClipBoard;
		std::string cutText;
		bool executed = false;
	};
}
#endif // !_CUTCOMMAND_H_
