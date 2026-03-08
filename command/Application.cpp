#include"Application.h"
#include"Cmd/CutCommand.h"
#include"Cmd/PasteCommand.h"
#include"Cmd/InsertCommand.h"
#include "Cmd/CopyCommand.h"
#include"CommandHistory.h"
#include"UI/Shortcut.h"
#include"UI/Button.h"
#include<iostream>
#include"UI/Editor.h"
#include <conio.h>
namespace
{
	void showInfo(const std::string& tip, const std::string& str1, const std::string& str2)
	{
		std::cout << tip << std::endl;
		std::cout << "================================================" << std::endl;
		std::cout << "剪切板内容：" << str1 << std::endl;
		std::cout << "文本框内容：" << str2 << std::endl;
		std::cout << "================================================\n" << std::endl;
	}
}

void app::Application::init()
{
	copyBtn = std::make_shared<ui::Button>(std::make_shared<cmd::CopyCommand>(shared_from_this()));
	cutBtn = std::make_shared<ui::Button>(std::make_shared<cmd::CutCommand>(shared_from_this()));
	pasteBtn = std::make_shared<ui::Button>(std::make_shared<cmd::PasteCommand>(shared_from_this()));
	copyShortcut = std::make_shared<ui::Shortcut>(std::make_shared<cmd::CopyCommand>(shared_from_this()));
	cutShortcut = std::make_shared<ui::Shortcut>(std::make_shared<cmd::CutCommand>(shared_from_this()));
	pasteShortcut = std::make_shared<ui::Shortcut>(std::make_shared<cmd::PasteCommand>(shared_from_this()));
	editor = std::make_shared<ui::Editor>();
	historyCommand = std::make_shared<cmd::CommandHistory>();
	running = true;
}

void app::Application::addIntoManager(const std::shared_ptr<cmd::Command>& command)
{
	historyCommand->addIntoStack(command);
}

app::Application::Application()
{
	running = false;
}

void app::Application::run()
{
	showMenu();
	do
	{
		int ch = _getch();
		switch (ch)
		{
		//Q 复制按钮
		case 'q':
			std::cout << "Q" << std::endl;
			if (copyBtn->click()) {
				std::cout << "复制成功~" << std::endl;
			}
			else {
				std::cout << "复制失败~" << std::endl;
			}
			break;

		//W 剪切按钮
		case 'w':
			std::cout << "W" << std::endl;
			if (cutBtn->click()) {
				addIntoManager(cutBtn->getCommand());
				std::cout << "剪切成功~" << std::endl;
			}
			else {
				std::cout << "没有可剪切的内容~" << std::endl;
			}
			break;

		//E 粘贴按钮
		case 'e':
			std::cout << "E" << std::endl;
			if (pasteBtn->click()) {
				addIntoManager(pasteBtn->getCommand());
				std::cout << "粘贴成功~" << std::endl;
			}
			else {
				std::cout << "剪切板为空，未执行粘贴~" << std::endl;
			}
			break;

		//R 复制快捷键
		case 'r':
			std::cout << "R" << std::endl;
			if (copyShortcut->key()) {
				std::cout << "复制成功~" << std::endl;
			}
			else {
				std::cout << "复制失败~" << std::endl;
			}
			break;

		//T 剪切快捷键
		case 't':
			std::cout << "T" << std::endl;
			if (cutShortcut->key()) {
				addIntoManager(cutShortcut->getCommand());
				std::cout << "剪切成功~" << std::endl;
			}
			else {
				std::cout << "没有可剪切的内容~" << std::endl;
			}
			break;

		//Y 粘贴快捷键
		case 'y':
			std::cout << "Y" << std::endl;
			if (pasteShortcut->key()) {
				addIntoManager(pasteShortcut->getCommand());
				std::cout << "粘贴成功~" << std::endl;
			}
			else {
				std::cout << "剪切板为空，未执行粘贴~" << std::endl;
			}
			break;

		//I 插入文本
		case 'i':
			std::cout << "I" << std::endl;
			{
				auto input = editor->edit();
				auto insertCommand = std::make_shared<cmd::InsertCommand>(shared_from_this(), input);
				if (insertCommand->execute()) {
					addIntoManager(insertCommand);
					std::cout << "输入成功，当前文本:" << editor->getText() << std::endl;
				}
				else {
					std::cout << "输入为空，未修改文本~" << std::endl;
				}
			}
			break;

		//N 撤销操作
		case 'n':
			std::cout << "N" << std::endl;
			historyCommand->undo();
			std::cout << "撤销成功~" << std::endl;
			break;
		//M 重做操作
		case 'm':
			std::cout << "M" << std::endl;
			historyCommand->redo();
			std::cout << "重做成功~" << std::endl;
			break;
		//S 展示当前内容
		case 's':
			std::cout << "S" << std::endl;
			showInfo("当前内容:", clipBoard, editor->getText());
			break;
		//; 退出程序
		case ';':
			std::cout << ";" << std::endl;
			running = false;
			break;
		//C: 清空屏幕
		case 'c':
			system("cls");
			showMenu();
			break;
		default:
			std::cout << "unknown key" << std::endl;
			break;
		}
	} while (running);
}

void app::Application::showMenu()
{
	std::cout << "=========================== 交互测试 ============================" << std::endl;
	std::cout << "Q-复制按钮 W-剪切按钮 E-粘贴按钮 R-复制快捷键 T-剪切快捷键 Y-粘贴快捷键 " << std::endl;
	std::cout << "I-编辑文本 N-撤销操作 M-重做操作 S-状态展示 C-清空屏幕   ;-退出程序" << std::endl;
	std::cout << "=================================================================" << std::endl;
}
