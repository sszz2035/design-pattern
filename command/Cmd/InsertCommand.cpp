#include"InsertCommand.h"
#include"Application.h"
#include"UI/Editor.h"
std::shared_ptr<cmd::Command> cmd::InsertCommand::clone()
{
	return std::make_shared<cmd::InsertCommand>(*this);
}
bool cmd::InsertCommand::execute()
{
	auto application = app.lock();
	if (!application || inputText.empty()) {
		return false;
	}
	savePreviousBackup();
	auto editor = application->getEditor();
	std::string editorTxt = editor->getText();
	editorTxt.append(inputText);
	editor->replaceText(editorTxt);
	saveAfterBackup();
	return true;
}

void cmd::InsertCommand::undo()
{
	auto application = app.lock();
	if (!application) {
		return;
	}
	application->getEditor()->replaceText(previousState);
}

void cmd::InsertCommand::redo()
{
	auto application = app.lock();
	if (!application) {
		return;
	}
	application->getEditor()->replaceText(afterState);
}

void cmd::InsertCommand::savePreviousBackup()
{
	auto application = app.lock();
	if (!application) {
		return;
	}
	previousState = application->getEditor()->getText();
}

void cmd::InsertCommand::saveAfterBackup()
{
	auto application = app.lock();
	if (!application) {
		return;
	}
	afterState = application->getEditor()->getText();
}
