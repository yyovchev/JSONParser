#include "TypeNumber.h"

TypeNumber::TypeNumber(double number)
{
    this->num = number;
}

TypeNumber::~TypeNumber()
{

}

JSONType *TypeNumber::clone() const
{
    return new TypeNumber(*this);
}

void TypeNumber::print(std::ostream &out, bool pretty, int offset) const
{
    out<<num;
}
