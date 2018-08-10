#include "TypeNULL.h"

TypeNULL::~TypeNULL()
{

}

JSONType *TypeNULL::clone() const
{
    new TypeNULL(*this);
}

void TypeNULL::print(std::ostream &out, bool pretty, int offset) const
{
    out<<"null";
}
