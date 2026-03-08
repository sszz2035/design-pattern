#include "Shortcut.h"
#include"Command.h"
bool ui::Shortcut::key()
{
	return command->execute();
}
