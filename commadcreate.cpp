#include "commadcreate.h"
#include "JSON/factory.h"
#include "JSON/JSONType.h"
#include <iostream>

CommadCreate::CommadCreate()
    :Command("create")
{

}

CommadCreate::~CommadCreate()
{

}

void CommadCreate::execute(jsonTable &jt) const
{
    char name[64];
    char type[16];
    char con[1024];

    std::cin>>name>>type;
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
            std::cout<<"<jsonName> -f <filename>  --- load from file\n"
                     <<"<jsonName> -t <text>  --- load from text\n"
                     <<"<jsonName> -n  --- empty obj\n";
            return;
        }
    }
    catch(std::exception &e){
        std::cout<<e.what()<<std::endl;
        return;
    }

    JSONVar var;
    var.json = json;
    var.name = name;
    var.name.append('\0');

    try{
        jt.add(var);
    }
    catch(std::exception &e){
        std::cout<<e.what()<<std::endl;
        delete json;
        return;
    }

    delete json;

    std::cout<<name<<" was created\n";
}

static CommadCreate cmcreate;
