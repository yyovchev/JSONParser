#include "commandadd.h"

#include "JSON/JSONItem.h"
#include "JSON/factory.h"

CommandAdd::CommandAdd()
    :Command("add")
{

}

CommandAdd::~CommandAdd()
{

}

void CommandAdd::execute(jsonTable &jt) const
{
    char name[64];
    char type[16];
    char value[64];
    char con[1024];

    std::cin>>name>>type>>value;
    String t(type);

    std::cin.ignore();
    std::cin.getline(con,1024);

    JSONType *json = nullptr;

    try{
        if(t == "-f")
            json = Factory::CreateFromFile(con);
        else if(t == "-t")
            json = Factory::CreateFromString(con);
        else if(t == "-j")
            json = getElement(con,jt);
        else{
            std::cout<<"<jsonName> -f <filename>  --- add file\n"
                     <<"<jsonName> -t <text>      --- add text\n"
                     <<"<jsonName> -j <json>      --- add obj\n";
            return;
        }
    }
    catch(std::exception &e){
        std::cout<<e.what()<<std::endl;
        return;
    }

    JSONItem item;
    item.setKey(value);
    item.setValue(json);

    try{
        JSONType* base = getElement(name,jt);
        base->addItem(json,value);
    }
    catch(std::exception &e){
        std::cout<<e.what()<<std::endl;
        delete json;
        return;
    }

    std::cout<<name<<" was added\n";
}

static CommandAdd commandAdd;
