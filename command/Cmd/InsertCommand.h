#ifndef INSERTCOMMAND_H_
#define INSERTCOMMAND_H_
#include"Command.h"
#include<string>
namespace cmd
{
	class InsertCommand :public Command
	{
	public:
		InsertCommand(std::shared_ptr<app::Application> app, const std::string& text)
			: Command(app), inputText(text) {}
		std::shared_ptr<Command> clone() override;
		bool execute() override;
		void undo() override;
		void redo() override;
	private:
		void savePreviousBackup();
		void saveAfterBackup();
	private:
		std::string previousState;
		std::string afterState;
		std::string inputText;
	};
}
#endif // !_INSERTCOMMAND_H_
