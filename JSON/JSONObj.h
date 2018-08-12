#ifndef JSONOBJ_H
#define JSONOBJ_H

#include "JSONType.h"
#include "JSONItem.h"

#include "vector/Vector.hpp"
#include "vector/String.hpp"

class JSONObj : public JSONType
{
public:
    typedef Vector<JSONItem*> ItemVector;
public:
    JSONObj();
    JSONObj(const JSONObj &other);
    JSONObj(const ItemVector &items);
    ~JSONObj();

    virtual JSONType* clone()const;
    virtual JSONType* getElement(const String &key);
    virtual const JSONType* getElement(const String &key) const;
    virtual void print(std::ostream &out,bool pretty = true, int offset = 0) const;
    virtual void setOnKey(const String &key,JSONType *newValue);
    virtual void search(JSONType* fidnValues, const String &key)const ;

    void addItem(const JSONItem& newItem);
    virtual void addItem(const JSONType* value, const char * key = nullptr);


private:
    void copyItems(const ItemVector &items);
    void clear();
    int checkID(const String &str)const;
    bool isKeyValid(const String &key)const;
    ItemVector getAllElement()const;
    JSONObj& operator=(const JSONObj&) = delete;

private:
    ItemVector items;
};

#endif // JSONOBJ_H
