#include "JSONObj.h"

#include <iostream>
JSONObj::JSONObj()
{

}

JSONObj::JSONObj(const JSONObj &other)
{
    copyItems(other.getAllElement());
}

JSONObj::JSONObj(const ItemVector &items)
{
    copyItems(items);
}

JSONObj::~JSONObj()
{
   clear();
}

JSONType* JSONObj::clone() const
{
    return new JSONObj(*this) ;
}

JSONType *JSONObj::getElement(const String &key)
{
    int el_key = checkID(key);
    return (el_key == -1 ) ? nullptr : items[el_key]->getValue();
}

const JSONType* JSONObj::getElement(const String &key) const
{
    int el_key = checkID(key);
    return (el_key == -1 ) ? nullptr : items[el_key]->getValue();
}

void JSONObj::print(std::ostream &out, bool pretty, int offset) const
{
    out<<"{";
    if (pretty) out<<"\n";
    int size = items.getSize();

    if (size){
        if (pretty) for (int i =0; i<offset; ++i) out<<"\t";
        items[0]->print(out,pretty,offset+1);
    }
    for (int i = 1; i<size; i++){
        out<<",";
        if (pretty){
            out << "\n";
            for (int i =0; i<offset; ++i) out<<"\t";
        }
        items[i]->print(out,pretty,offset+1);
    }
    if (pretty){
        out << "\n";
        for (int i =0; i<offset-1; ++i) out<<"\t";
    }
    out<<"}";

}

void JSONObj::setOnKey(const String &key,JSONType *newValue)
{
    int size = this->items.getSize();

    for(int i = 0; i<size; i++){
        if (items[i]->getKey() == key){
            items[i]->setValue(newValue);
            return;
        }
    }
}

void JSONObj::addItem(const JSONItem &newItem)
{
    JSONItem *item = new JSONItem(newItem);
    items.append(item);
}

void JSONObj::copyItems(const ItemVector &items)
{
    int size = items.getSize();

    for (int i = 0; i<size; ++i){
        this->items.append(new JSONItem(*(items[i])));
    }
}

int JSONObj::checkID(const String &str) const
{
    int size = this->items.getSize();

    for(int i = 0; i<size; i++){
        if (items[i]->getKey() == str)
            return i;
    }
    return -1;
}

void JSONObj::clear(){
    int size = items.getSize();

    for (int i = 0; i<size; ++i)
        delete items[i];
}

JSONObj::ItemVector JSONObj::getAllElement()const
{
    return items;
}
