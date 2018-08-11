#ifndef JSONSIPLETYPE_H
#define JSONSIPLETYPE_H

#include "JSONType.h"

#include <exception>

class JSONSipleType : public JSONType
{
public:
    virtual ~JSONSipleType();

    virtual JSONType* clone() const = 0;

    virtual JSONType* getElement(const String &index);
    virtual const JSONType* getElement(const String &index)const;
    virtual void setOnKey(const String &key, JSONType *newValue);

};

#endif // JSONSIPLETYPE_H
