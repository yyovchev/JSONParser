#ifndef COMMADCREATE_H
#define COMMADCREATE_H

#include "command.h"

class CommadCreate : public Command
{
public:
    CommadCreate();
    virtual ~CommadCreate();
    virtual void execute(jsonTable &jt)const;
};

#endif // COMMADCREATE_H
