#include "commandprint.h"

#include "JSON/JSONType.h"
#include <iostream>

CommandPrint::CommandPrint()
    :Command("print")
{

}

CommandPrint::~CommandPrint()
{

}

void CommandPrint::execute(jsonTable &jt) const
{
    char name[200];
    std::cin>>name;

    JSONType *json = nullptr;
    try{
        json = getElement(name, jt);
    }
    catch(std::exception &e){
        std::cout<<e.what()<<std::endl;
        return;
    }

    if(json)
        json->print(std::cout);
    else
        std::cout<<name<<" is not created \n";
    std::cout<<std::endl;
}

static CommandPrint ommandPrint;
