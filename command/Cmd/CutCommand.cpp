#include"CutCommand.h"
#include"Application.h"
#include"UI/Editor.h"
void cmd::CutCommand::saveBackup()
{
	auto application = app.lock();
	if (!application) {
		return;
	}
	preText = application->getEditor()->getText();
	preClipBoard = application->getClipBoard();
	cutText = preText;
}

std::shared_ptr<cmd::Command> cmd::CutCommand::clone()
{
	return std::make_shared<cmd::CutCommand>(*this);
}

bool cmd::CutCommand::execute()
{
	auto application = app.lock();
	if (!application) {
		return false;
	}
	auto editor = application->getEditor();
	executed = false;
	saveBackup();
	if (cutText.empty()) {
		return false;
	}
	executed = true;
	application->setClipBoard(cutText);
	editor->replaceText("");
	return true;
}

void cmd::CutCommand::undo()
{
	if (!executed) {
		return;
	}
	auto application = app.lock();
	if (!application) {
		return;
	}
	auto editor = application->getEditor();
	application->setClipBoard(preClipBoard);
	editor->replaceText(preText);
}
void cmd::CutCommand::redo()
{
	if (!executed) {
		return;
	}
	auto application = app.lock();
	if (!application) {
		return;
	}
	application->setClipBoard(cutText);
	application->getEditor()->replaceText("");
}
