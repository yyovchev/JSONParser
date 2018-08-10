#include "command.h"
#include "menu.h"

Command::Command(const String &cmdStr)
    :cmdString(cmdStr)
{
   cmdString.append('\0');
   Menu::getMenu().registerCommand(this);
}

Command::Command(const char *cmdStr)
    :cmdString(cmdStr)
{
   Menu::getMenu().registerCommand(this);
}


Command::~Command()
{

}

const String &Command::getName() const
{
    return this->cmdString;
}
