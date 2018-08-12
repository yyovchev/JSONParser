#include "CommandSearch.h"

#include "JSON/JSONArray.h"

CommandSearch::CommandSearch()
    :Command("search")
{

}

CommandSearch::~CommandSearch()
{

}

void CommandSearch::execute(jsonTable &jt) const
{
    char name[200], newname[200], key[200];
    std::cin>>newname >> name >> key;

    JSONType *json = nullptr;
    try{
        json = getElement(name, jt);
    }
    catch(std::exception &e){
        std::cout<<e.what()<<std::endl;
        return;
    }

    String Key(key);
    Key.append('\0');

    JSONType *srch = new JSONArray;
    json->search(srch,Key);


    JSONVar var(newname, srch);

    try{
        jt.add(var);
    }
    catch(std::exception &e){
        std::cout<<e.what()<<std::endl;
        delete json;
        return;
    }
    delete srch;

    std::cout<<newname<<" was created from search\n";
}

static CommandSearch commandSearch;
