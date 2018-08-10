#ifndef COMMANDDELETE_H
#define COMMANDDELETE_H

#include "command.h"

class CommandDelete : public Command
{
public:
    CommandDelete();
    virtual ~CommandDelete();
    virtual void execute(jsonTable &jt) const;
};

#endif // COMMANDDELETE_H
