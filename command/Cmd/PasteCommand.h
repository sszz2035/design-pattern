#ifndef PASTECOMMAND_H_
#define PASTECOMMAND_H_
#include"Command.h"
#include<string>
namespace cmd
{
	class PasteCommand :public Command
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
		std::string textBackup;
		std::string clipBackup;
	};
}
#endif // !_PASTECOMMAND_H_
