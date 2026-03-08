#ifndef EDITOR_H_
#define EDITOR_H_
#include<string>
namespace ui
{
	class Editor
	{
	public:
		std::string edit();
		std::string getText() const { return text; }
		std::string delText();
		std::string replaceText(const std::string& txt);
	private:
		std::string text;
	};
}
#endif // !_EDITOR_H_
