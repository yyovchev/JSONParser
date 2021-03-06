#include "JSONArray.h"

#include<stdio.h>
#include<exception>

JSONArray::JSONArray()
{

}

JSONArray::JSONArray(const JSONArray &other)
{
    copyItems(other.getAllElements());
}

JSONArray::JSONArray(const TypeArray &items)
{
    copyItems(items);
}

JSONArray::~JSONArray()
{
    clear();
}

JSONType* JSONArray::clone()const
{
    return new JSONArray(*this);
}


JSONType* JSONArray::getElement(const String &key)
{
    int index = parseKey(key);

    return items[index];
}

const JSONType* JSONArray::getElement(const String &key)const
{
    int index = parseKey(key);

    return items[index];
}

void JSONArray::print(std::ostream &out,bool pretty, int offset) const
{
    out<<"[\n";

    int size = items.getSize();

    if (size > 0 ){
        if (pretty)for (int i = 0; i<offset; ++i) out<<"\t";
        items[0]->print(out,pretty,offset+1);
    }

    for (int i = 1 ; i<size; i++){
        out<<",";
        if (pretty){
            out<<"\n";
            for (int i = 0; i<offset*pretty; ++i) out<<"\t";
        }
        items[i]->print(out,pretty,offset+1);
    }

    if (pretty){
        out<<"\n";
        for (int i = 0; i<offset-1*pretty; ++i) out<<"\t";
    }

    out<<"]";
}

void JSONArray::setOnKey(const String &key, JSONType *newValue)
{
    int size = items.getSize();
    int index = parseKey(key);
    delete items[index];
    items[index] = newValue->clone();
}

void JSONArray::addItem(const JSONType *value, const char *key)
{
    JSONType *new_value = value->clone();
    items.append(new_value);
}

void JSONArray::search(JSONType *fidnValues, const String &key) const
{
    int size = items.getSize();
    for (int i =0; i<size; ++i)
        items[i]->search(fidnValues, key);
}

bool JSONArray::isKeyValid(const String &key) const
{
    int size = key.getSize();

    for(int i = 0; i < size; ++i)
        if ((key[i]< '0' || key[i]>'9') && key[i] != '\0')
            return false;

    return true;
}

int JSONArray::parseKey(const String &key) const
{
    String msg(key);
    msg.removenulls();
    if (!(isKeyValid(key))){
        msg += ": invalid key";
        throw std::invalid_argument(msg);
    }

    int index;
    sscanf(key, "%d", &index);

    if(index > items.getSize()){
        msg += ": size error";
        throw std::invalid_argument(msg);
    }

    return index;
}

void JSONArray::clear(){
    int size = items.getSize();

    for (int i = 0; i<size; ++i)
        delete items[i];
}

JSONArray::TypeArray JSONArray::getAllElements() const
{
    return items;
}

void JSONArray::copyItems(const TypeArray &items)
{
    int size = items.getSize();

    for (int i = 0; i<size; ++i)
        this->items.append(items[i]->clone());
}
