#ifndef COMMANSSWAP_H
#define COMMANSSWAP_H

#include "command.h"

class CommansSwap : public Command
{
public:
    CommansSwap();
    virtual ~CommansSwap();
    virtual void execute(jsonTable &jt)const;
private:
    JSONType *getPevElent(const String &string, jsonTable &jt, String &lastkey) const;
};

#endif // COMMANSSWAP_H
