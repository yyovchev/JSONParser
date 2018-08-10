#ifndef TYPENULL_H
#define TYPENULL_H

#include "JSONSipleType.h"

class TypeNULL : public JSONSipleType
{
public:
    ~TypeNULL();
    virtual JSONType* clone()const;
    virtual void print(std::ostream &out, bool pretty = true, int offset = 0) const;
};

#endif // TYPENULL_H
