#ifndef JSONTABLE_H
#define JSONTABLE_H

#include "vector/String.hpp"
#include "vector/Vector.hpp"
#include "JSON/JSONType.h"

#include "exception"

class JSONVar
{
public:
    String name;
    JSONType *json;

    JSONVar()
        : json(nullptr)
    {}
    JSONVar(const String &key, const JSONType *value){
        name = key;
        this->name.append('\0');
        json = value->clone();
    }
    ~JSONVar()
    {}

    JSONVar& operator =(const JSONVar &other)
    {
        name = other.name;
        json = other.json->clone();
        return *this;
    }
};

class jsonTable : public Vector<JSONVar>
{
public:
    jsonTable();
    ~jsonTable();
    JSONType* find(const String &string);
    void add(const JSONVar &newItem);
    void remove(const String &string);

};

#endif // JSONTABLE_H
