#ifndef FACTORY_H
#define FACTORY_H

#include "JSONObj.h"
#include "JSONArray.h"
#include "JSONItem.h"
#include "TypeBool.h"
#include "TypeNULL.h"
#include "TypeNumber.h"
#include "TypeString.h"

#include "vector/String.hpp"

#include <fstream>
#include <exception>
#include <istream>

#include <iostream>

class Factory
{
public:
    static JSONObj* CreateFromFile(const char *filname);
    static JSONObj* CreateFromFile(const String &filename);

    static JSONObj* CreateJSONObject();




private:
    Factory();
    static JSONType* CreateNewItemValue();
    static String ItemKey();
    static void init(std::istream &in);
    static TypeString* CreateString();
    static TypeNumber* CreateNumber();
    static JSONType* CreateWordType();  //true,false,null
    static JSONArray* CreateArray();

private:
    static String jsFile;
    static int cur;
    static int size;

};

#endif // FACTORY_H
