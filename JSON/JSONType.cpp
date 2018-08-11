#include "JSONType.h"

JSONType::~JSONType()
{

}

JSONType* JSONType::getElement(const char *index)
{
    if (!index)
        throw "invalid pointer";
    String inx(index);
    return getElement(inx);
}

const JSONType* JSONType::getElement(const char *index)const
{
    if (!index)
        throw "invalid pointer";
    String inx(index);
    return getElement(inx);
}

JSONType* JSONType::operator [](const String &string)
{
    return getElement(string);
}

const JSONType* JSONType::operator [](const String &string)const
{
    return getElement(string);
}
