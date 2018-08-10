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
