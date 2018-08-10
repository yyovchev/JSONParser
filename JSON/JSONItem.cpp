#include "JSONItem.h"

JSONItem::JSONItem()
    :value(nullptr)
    ,key("")
{}

JSONItem::JSONItem(const JSONItem &other)
    :key(other.getKey())
{
    this->value = other.getValue()->clone();
}

JSONItem::JSONItem(const String &key, const JSONType *value)
    :key(key)
{
    if(!isKeyValid(this->key))
        throw std::invalid_argument(this->key + " is not a valid key");
    this->value = value->clone();
    this->key.append('\0');
}

JSONItem::JSONItem(const char *key, const JSONType *value)
    :key(key)
{
    this->value = value->clone();
    this->key.append('\0');
}

JSONItem::~JSONItem()
{
    delete value;
}

String JSONItem::getKey()const
{
    return this->key;
}

JSONType* JSONItem::getValue()
{
    return this->value;
}

const JSONType* JSONItem::getValue()const
{
    return this->value;
}

void JSONItem::setKey(const String &key)
{
    if(!isKeyValid(key))
        throw std::invalid_argument("Invalid Key!");

    this->key = key;
    this->key.append('\0');
}

void JSONItem::setKey(const char *key)
{
    setKey(String(key));
}

void JSONItem::setValue(const JSONType *value)
{
   // if (this->value)
    delete this->value;

    this->value = value ? value->clone() : nullptr;
}

JSONItem& JSONItem::operator=(const JSONItem &other)
{
    if(this != &other)
    {
        this->key = other.getKey();
        delete this->value;
        this->value = other.getValue()->clone();
    }

    return *this;
}

bool JSONItem::isKeyValid(const String &key)
{
    int len = key.getSize();

    for (int i = 0; i<len; ++i){
        char ch = key[i];
        bool Cl = (ch >= 'A' && ch <='Z');      //is capital letter
        bool Ll = (ch >= 'a' && ch <='z');      //is lowercase letter
        bool num = (ch >= '0' && ch<='9');     // numbers
        bool other = (ch=='_' || ch =='-' || '\'' || '\"');
        if (!(Cl || Ll || num || other))
            return false;
    }

    return true;
}

void JSONItem::print(std::ostream &out, bool pretty, int offset) const
{
    out<<key<<":";
    value->print(out,pretty,offset);
}
