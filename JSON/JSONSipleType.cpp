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
