#include "commanddelete.h"

#include "JSON/JSONType.h"
#include <iostream>

CommandDelete::CommandDelete()
    :Command("delete")
{

}

CommandDelete::~CommandDelete()
{

}

void CommandDelete::execute(jsonTable &jt) const
{
    char name[128];
    std::cin>>name;
    String n(name);
    jt.remove(n);
    std::cout<<name <<" was deleted \n";
}

static CommandDelete commandDelete;
