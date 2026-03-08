#include"CopyCommand.h"
#include"Application.h"
#include "UI/Editor.h"
std::shared_ptr<cmd::Command> cmd::CopyCommand::clone()
{
	return std::make_shared<cmd::CopyCommand>(*this);
}
bool cmd::CopyCommand::execute()
{
	auto application = app.lock();
	if (!application) {
		return false;
	}
	application->setClipBoard(application->getEditor()->getText());
	return true;
}
