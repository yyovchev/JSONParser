#ifndef TYPENUMBER_H
#define TYPENUMBER_H

#include "JSONSipleType.h"

class TypeNumber : public JSONSipleType
{
public:
    TypeNumber() = default;
    TypeNumber(double number);
    ~TypeNumber();
    virtual JSONType* clone()const;
    virtual void print(std::ostream &out, bool pretty = true, int offset = 0) const;


private:
    double num;
};

#endif // TYPENUMBER_H
