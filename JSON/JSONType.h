#ifndef JSONTYPE_H
#define JSONTYPE_H

#include "vector/String.hpp"

#include <ostream>

class JSONType
{
public:
    virtual ~JSONType();

    virtual JSONType* clone()const = 0;

    JSONType* getElement(const char *index);
    const JSONType* getElement(const char *index)const;

    virtual JSONType* getElement(const String &index) = 0;
    virtual const JSONType* getElement(const String &index)const = 0;

    virtual void print(std::ostream &out, bool pretty = true, int offset = 0)const = 0;
    virtual void setOnKey(const String &key,JSONType *newValue) = 0;
    virtual void addItem(const JSONType* value, const char * key = nullptr) = 0;
    virtual void search(JSONType* fidnValues, const String &key)const = 0;
    JSONType* operator[](const String &string) ;
    const JSONType* operator [](const String &string)const;
};

#endif // JSONTYPE_H
