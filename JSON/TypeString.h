#ifndef TYPESTRING_H
#define TYPESTRING_H

#include "JSONSipleType.h"
#include "vector/String.hpp"

class TypeString : public JSONSipleType
{
public:
    TypeString() = default;
    TypeString(const char *string);
    TypeString(const String &string);
    ~TypeString();
    virtual JSONType* clone()const;
    virtual void print(std::ostream &out, bool pretty = true, int offset = 0) const;

private:
    String string;
};

#endif // TYPESTRING_H
