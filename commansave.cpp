#include "commansave.h"

#include <fstream>

CommanSave::CommanSave()
    :Command("save")
{

}

CommanSave::~CommanSave()
{

}

void CommanSave::execute(jsonTable &jt) const
{
    char name[64];
    char type[16];
    char filename[200];

    std::cin>>name>>type>>filename;
    String t(type);

    std::ifstream f(filename);
    if (f.good()){
        char ch;
        std::cout <<"File exists. Overwrite? [y/n]";
        std::cin>>ch;
        if (ch == 'n'){
            f.close();
            return;
        }
    }

    JSONType *json = nullptr;
    try{
        json = getElement(name, jt);
    }
    catch(std::exception &e){
        std::cout<<e.what()<<std::endl;
        return;
    }


    std::ofstream file(filename);

    if (!f.is_open() || !file.good()){
        std ::cout<<"Problem with file\n";
        return;
    }

    if(t == "-s")
        json->print(file,false);
    else
        json->print(file);


    std::cout<<name<<" was saved in "<<filename<<std::endl;

    file.close();
}

static CommanSave commandSave;
