#ifndef JSONITEM_H
#define JSONITEM_H

#include "vector/String.hpp"
#include "JSONType.h"

#include <exception>
#include <ostream>

class JSONItem
{
public:
    JSONItem();
    JSONItem(const JSONItem& other);
    JSONItem(const String &key, const JSONType *value);
    JSONItem(const char* key, const JSONType *value);

    ~JSONItem();

    String getKey() const;
    JSONType* getValue();
    const JSONType* getValue()const;

    void setKey(const String &key);
    void setKey(const char* key);
    void setValue(const JSONType *value);

    JSONItem& operator=(const JSONItem &other);

    void print(std::ostream &out,bool pretty = true,int offset = 0)const;

private:
    bool isKeyValid(const String& key);
    
private:
    String key;
    JSONType *value;

};

#endif // JSONITEM_H
