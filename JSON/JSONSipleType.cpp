#include "JSONSipleType.h"

JSONSipleType::~JSONSipleType()
{

}

JSONType *JSONSipleType::getElement(const String &index)
{
    throw std::invalid_argument("ERROR ! - ST getElement");
}

const JSONType *JSONSipleType::getElement(const String &index) const
{
    throw std::invalid_argument("ERROR ! - ST getElement");
}

void JSONSipleType::setOnKey(const String &key, JSONType *newValue)
{
    throw std::invalid_argument("ERROR ! - ST setOnValue");
}

void JSONSipleType::addItem(const JSONType *value, const char *key)
{
    throw std::invalid_argument("ERROR ! - ST addItem");

}

void JSONSipleType::search(JSONType *fidnValues, const String &key) const
{
    ;
}
