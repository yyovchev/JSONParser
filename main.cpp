#include <iostream>
#include "vector/String.hpp"
#include "JSON/JSONArray.h"
#include "JSON/JSONItem.h"
#include "JSON/TypeString.h"
#include "JSON/TypeNumber.h"
#include "JSON/TypeNULL.h"
#include "JSON/JSONObj.h"
#include "JSON/TypeBool.h"

#include <exception>
#include <fstream>
#include <cstring>
#include <string>

#include "JSON/factory.h"

using namespace std;

int main()
{
    JSONObj obj;

    JSONItem item("first",new TypeString("first el"));
    JSONItem item1("first",new TypeNULL);
    JSONItem item2("first",new TypeNumber(3));

    obj.addItem(item);
    obj.addItem(item1);
    obj.addItem(item2);

    JSONArray array;
    array.addItem(new TypeString("first el"));
    array.addItem(new TypeNULL);
    array.addItem(new TypeNULL);
    array.addItem(new TypeBool(0));

//    array.print(cout);


    array.addItem(obj.clone());
    JSONItem ar("array", array.clone());
    obj.addItem(ar);

    //std::ofstream file("test1.txt");

    //obj.print(file);
    //file.close();

    try {
        JSONObj *o = Factory::CreateFromFile("tests/test2.json");
        o->print(cout);

    } catch (exception &e) {
        cout<<e.what();
    }

    cout<<"\nwow\n";

    return 0;
}
