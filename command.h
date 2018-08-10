#ifndef COMMAND_H
#define COMMAND_H

#include "vector/String.hpp"
#include "jsontable.h"

#include <iostream>


class Command
{
public:
    Command(const String &cmdStr);
    Command(const char *cmdStr);
    virtual ~Command();
    virtual void execute(jsonTable &jt)const = 0;

    const String& getName()const;

private:
    String cmdString;
};

#endif // COMMAND_H
