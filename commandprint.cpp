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
    char name[128];
    std::cin>>name;
    String Name(name);

    JSONType *json = jt.find(Name);

    if(json)
        json->print(std::cout);
    else
        std::cout<<name<<" is not created \n";
    std::cout<<std::endl;
}

static CommandPrint ommandPrint;
