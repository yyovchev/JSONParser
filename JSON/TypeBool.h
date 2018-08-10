#ifndef TYPEBOOL_H
#define TYPEBOOL_H

#include "JSONSipleType.h"


class TypeBool :public JSONSipleType
{
public:
    TypeBool() = default;
    TypeBool(bool value);
    ~TypeBool();

    virtual JSONType* clone() const;
    virtual void print(std::ostream &out, bool pretty = true, int offset = 0) const;

private:
    bool value;
};

#endif // TYPEBOOL_H
