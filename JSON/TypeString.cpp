#include "TypeString.h"

TypeString::TypeString(const char *string)
    :string(string)
{
    this->string.append('\0');
}

TypeString::TypeString(const String &string)
    :string(string)
{
    this->string.append('\0');
}

TypeString::~TypeString()
{

}

JSONType *TypeString::clone() const
{
    return new TypeString(*this);
}

void TypeString::print(std::ostream &out, bool pretty, int offset) const
{
    out<<"\""<<string<<"\"";
}
