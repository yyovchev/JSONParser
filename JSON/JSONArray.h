#ifndef JSONARRAY_H
#define JSONARRAY_H

#include "JSONType.h"

#include "vector/Vector.hpp"

class JSONArray : public JSONType
{
public:
    typedef Vector<JSONType*> TypeArray;
public:
    JSONArray();
    JSONArray(const JSONArray &other);
    JSONArray(const TypeArray &items);
    ~JSONArray();

    virtual JSONType* clone()const;
    virtual JSONType* getElement(const String &key);             // key must be a number
    virtual const JSONType* getElement(const String &key) const; // key must be a number
    virtual void print(std::ostream &out, bool pretty = true, int offset = 0) const;

    void addItem(JSONType *item);

private:
    bool isKeyValid(const String &key)const;
    int parseKey(const String &key)const;
    void clear();
    TypeArray getAllElements()const;
    void copyItems(const TypeArray &items);

private:
    TypeArray items;
};

#endif // JSONARRAY_H
