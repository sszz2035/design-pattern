#include "Button.h"
#include "Command.h"
bool ui::Button::click()
{
	return command->execute();
}
