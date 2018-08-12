#ifndef COMMANSAVE_H
#define COMMANSAVE_H

#include "command.h"

class CommanSave : public Command
{
public:
    CommanSave();
    virtual ~CommanSave();

    virtual void execute(jsonTable &jt) const;
};

#endif // COMMANSAVE_H
