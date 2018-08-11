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

    json->print(std::cout);
}

static CommandPrint ommandPrint;
