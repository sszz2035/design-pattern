#include"PasteCommand.h"
#include"Application.h"
#include"UI/Editor.h"
std::shared_ptr<cmd::Command> cmd::PasteCommand::clone()
{
	return std::make_shared<cmd::PasteCommand>(*this);
}
bool cmd::PasteCommand::execute()
{
	auto application = app.lock();
	if (!application) {
		return false;
	}
	auto editor = application->getEditor();
	std::string appText = application->getClipBoard();
	if (appText.empty()) {
		return false;
	}
	saveBackup();
	std::string curText = editor->getText();
	curText.append(appText);
	editor->replaceText(curText);
	return true;
}

void cmd::PasteCommand::undo()
{
	auto application = app.lock();
	if (!application) {
		return;
	}
	application->getEditor()->replaceText(textBackup);
}

void cmd::PasteCommand::redo()
{
	auto application = app.lock();
	if (!application || clipBackup.empty()) {
		return;
	}
	std::string text = application->getEditor()->getText().append(clipBackup);
	application->getEditor()->replaceText(text);
}

void cmd::PasteCommand::saveBackup()
{
	auto application = app.lock();
	if (!application) {
		return;
	}
	textBackup = application->getEditor()->getText();
	clipBackup = application->getClipBoard();
}
