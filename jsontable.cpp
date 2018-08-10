#include "jsontable.h"

jsonTable::jsonTable()
{

}

jsonTable::~jsonTable()
{
    for(int i = 0; i < size; ++i)
        delete data[i].json;
}

JSONType* jsonTable::find(const String &string)
{
    int size = this->size;
    for(int i = 0; i < size; ++i)
        if (data[i].name == string)
            return data[i].json;
    return nullptr;
}

void jsonTable::add(const JSONVar &newItem)
{
   if(find(newItem.name))
        throw std::invalid_argument("name is used");

   Vector::append(newItem);
}

void jsonTable::remove(const String &string)
{
    int size = this->size;
    for(int i = 0; i < size; ++i)
        if (data[i].name == string)
        {
            delete data[i].json;
            Vector::remove(i);
            return;
        }
}
