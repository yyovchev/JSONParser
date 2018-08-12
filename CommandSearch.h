#ifndef COMMANDSEARCH_H
#define COMMANDSEARCH_H

#include "command.h"

class CommandSearch : public Command
{
public:
    CommandSearch();
    virtual ~CommandSearch();

    virtual void execute(jsonTable &jt) const;
};

#endif // COMMANDSEARCH_H
