#ifndef MENU_H
#define MENU_H

#include "vector/Vector.hpp"
#include "vector/String.hpp"
#include "JSON/JSONType.h"
#include "jsontable.h"
#include "command.h"

#include <iostream>
#include <exception>

//commands
#include "commadcreate.h"


class Command;
class Menu
{
public:
    static Menu& getMenu();

private:
    Menu();
    ~Menu();
    Menu(const Menu &menu) = delete;
    Menu& operator =(const Menu &menu) = delete;

    typedef Vector<const Command*> Commands;

public:
    void execute();
    void registerCommand(const Command *cmd);

private:
    jsonTable usedJsons;
    Commands commands;
    char *input;
    bool quit;

};

#endif // MENU_H
