#ifndef COMMANDADD_H
#define COMMANDADD_H

#include "command.h"
#include "jsontable.h"

class CommandAdd : public Command
{
public:
    CommandAdd();
    virtual ~CommandAdd();

    virtual void execute(jsonTable &jt) const;
};

#endif // COMMANDADD_H
