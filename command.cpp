#include "command.h"
#include "menu.h"

Command::Command(const String &cmdStr)
    :cmdString(cmdStr)
{
   cmdString.append('\0');
   Menu::getMenu().registerCommand(this);
}

Command::Command(const char *cmdStr)
    :cmdString(cmdStr)
{
   Menu::getMenu().registerCommand(this);
}


Command::~Command()
{

}

const String &Command::getName() const
{
    return this->cmdString;
}

JSONType* Command::getElement(const String &string, jsonTable &jt) const
{
    Vector<String> keys = getKeys(string);
    keys[0].append('\0');
    JSONType *json = jt.find(keys[0]);

    if(!json)
        throw std::invalid_argument(keys[0] + ": json is not created!");

    if (keys.getSize() == 1)
        return json;

    int size = keys.getSize();

    for (int i = 1; i<size; ++i){
        json = json->getElement(keys[i]);

        if(!json)
            throw std::invalid_argument(keys[i] + ": key not found!");
    }

    return json->clone();
}

Vector<String> Command::getKeys(const String &string)const
{
    Vector<String> keys;
    String name;
    int size = string.getSize();

    char ch;
    int cur = 0;

    for (; cur<size; ++cur){
        ch = string[cur];
        if (ch == '[')
            break;
        name.append(ch);
    }
    keys.append(name);
    if (cur == size)    return keys;

    String key;
    while(cur < size && string[cur] == '['){
        ++cur;
        key = "";
        for(; cur<size && string[cur] != ']'; ++cur){
            ch = string[cur];
            key.append(ch);
        }
        ++cur;
        keys.append(key);
    }

    if (cur != size)
        throw std::invalid_argument(key + " missing ] !");

    return keys;
}
