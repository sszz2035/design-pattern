#ifndef COMMANDHISTORY_H_
#define COMMANDHISTORY_H_
#include<stack>
#include<memory>
namespace cmd {
	class Command;
	class CommandHistory
	{
	public:
		void addIntoStack(const std::shared_ptr<Command>& command);
		void undo();
		void redo();
	private:
		std::stack<std::shared_ptr<Command>>undoStack;
		std::stack<std::shared_ptr<Command>>redoStack;
	};
}
#endif // !_COMMANDHISTORY_H_