#include"CommandHistory.h"
#include"Command.h"
void cmd::CommandHistory::addIntoStack(const std::shared_ptr<Command>& command)
{
	auto op = command->clone();
	undoStack.push(op);
	if (!redoStack.empty())
	{
		redoStack = std::stack<std::shared_ptr<cmd::Command>>();
	}
}
void cmd::CommandHistory::undo()
{
	if (undoStack.empty()) {
		return;
	}
	auto op = undoStack.top();
	undoStack.pop();
	redoStack.push(op);
	op->undo();
}
void cmd::CommandHistory::redo()
{
	if (redoStack.empty()) {
		return;
	}
	auto op = redoStack.top();
	redoStack.pop();
	undoStack.push(op);
	op->redo();
}
 