#include "commansswap.h"

CommansSwap::CommansSwap()
    :Command("swap")
{

}

CommansSwap::~CommansSwap()
{

}

void CommansSwap::execute(jsonTable &jt)const
{
    char name1[224];
    char name2[224];

    std::cin>>name1>>name2;

    JSONType *json1 = nullptr;
    JSONType *json2 = nullptr;
    JSONType *temp = nullptr;

    String last_key1;
    String last_key2;

    try {
       json1 = getPevElent(name1,jt,last_key1);
       json2 = getPevElent(name2,jt,last_key2);

       temp = (*json1)[last_key1]->clone();
       json1->setOnKey(last_key1, (*json2)[last_key2]);
       json2->setOnKey(last_key2, temp);

    } catch (std::exception &e) {
        std::cout<<e.what()<<"\n";
    }

}

JSONType* CommansSwap::getPevElent(const String &string, jsonTable &jt, String &lastkey)const
{
    Vector<String> keys = getKeys(string);
    keys[0].append('\0');
    JSONType *json = jt.find(keys[0]);

    if(!json){
        keys[0].removenulls();
        throw std::invalid_argument(keys[0] + ": json is not created!");
    }

    if (keys.getSize() == 1)
        throw std::invalid_argument("jsons cant be swaped");

    int size = keys.getSize();

    int i;
    for (i = 1; i<size-1; ++i){
        keys[i].append('\0');
        json = json->getElement(keys[i]);


        if(!json){
            keys[i].removenulls();
            throw std::invalid_argument(keys[i] + ": key not found!");
        }
    }

    lastkey = keys[i];
    lastkey.append('\0');

    return json;
}

static CommansSwap commandSwap;
