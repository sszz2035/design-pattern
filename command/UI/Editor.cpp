#include "Editor.h"
#include <iostream>
std::string ui::Editor::edit()
{
	std::cout << "当前文本:" << text << std::endl;
	std::cout << "请输入文本:";
	std::string input;
	std::getline(std::cin, input);
	return input;
}

std::string ui::Editor::delText()
{
	std::string temp = text;
	text.clear();
	return temp;
}

std::string ui::Editor::replaceText(const std::string& txt)
{
	std::string temp = text;
	text = txt;
	return temp;
}
