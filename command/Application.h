#ifndef APPLICATION_H_
#define APPLICATION_H_
#include<memory>
#include<string>
#include "Command.h"
namespace ui 
{
	class Button;
	class Editor;
	class Shortcut;
}
namespace cmd
{
	class CommandHistory;
}
namespace app
{
	class Application :public std::enable_shared_from_this<Application>
	{
	public:
		Application();
		void run();
		std::shared_ptr<ui::Editor>getEditor() { return editor; }
		std::string getClipBoard() { return clipBoard; }
		void init();
		void setClipBoard(const std::string& txt) { clipBoard = txt; }
	private:
		void addIntoManager(const std::shared_ptr<cmd::Command>& command);
		void showMenu();
	private:
		std::shared_ptr<ui::Button>copyBtn;
		std::shared_ptr<ui::Button>cutBtn;
		std::shared_ptr<ui::Button>pasteBtn;
		std::shared_ptr<ui::Shortcut>copyShortcut;
		std::shared_ptr<ui::Shortcut>cutShortcut;
		std::shared_ptr<ui::Shortcut>pasteShortcut;
		std::shared_ptr<cmd::CommandHistory>historyCommand;
		std::shared_ptr<ui::Editor>editor;
		std::string clipBoard;
		bool running;
	};
}

#endif // !APPLICATION_H_
