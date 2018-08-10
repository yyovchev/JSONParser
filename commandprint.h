#ifndef COMMANDPRINT_H
#define COMMANDPRINT_H

#include "command.h"

class CommandPrint: public Command
{
public:
    CommandPrint();
    virtual ~CommandPrint();
    virtual void execute(jsonTable &jt)const;
};

#endif // COMMANDPRINT_H
