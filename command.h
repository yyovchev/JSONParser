#ifndef COMMAND_H
#define COMMAND_H

#include "vector/Vector.hpp"
#include "vector/String.hpp"
#include "jsontable.h"

#include <iostream>
#include <exception>


class Command
{
public:
    Command(const String &cmdStr);
    Command(const char *cmdStr);
    virtual ~Command();
    virtual void execute(jsonTable &jt)const = 0;

    const String& getName()const;

protected:
    JSONType* getElement(const String &string, jsonTable &jt)const;
    Vector<String> getKeys(const String &string)const;

private:
    String cmdString;
};

#endif // COMMAND_H
