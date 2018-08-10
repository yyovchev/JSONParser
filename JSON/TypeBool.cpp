#include "TypeBool.h"

TypeBool::TypeBool(bool value)
    :value(value)
{

}

TypeBool::~TypeBool()
{

}

JSONType *TypeBool::clone() const
{
    return new TypeBool(*this);
}

void TypeBool::print(std::ostream &out, bool pretty, int offset) const
{
    out<< (value ? "True" : "False");
}
