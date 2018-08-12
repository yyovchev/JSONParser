#include "menu.h"

Menu::Menu()
{
    input = new char[64];
    quit = false;
}

Menu::~Menu()
{
    delete[] input;
}

void Menu::execute()
{

    int size = commands.getSize();

    using namespace std;
    do {
        cout<<">";
        cin>>input;
        if (!std::cin.good()) {
            cin.clear();
            cin.ignore(64, '\n');
            cout << "Problem with input, try again!\n";
            continue;
        }

        if (strcmp(input, "quit") == 0){
            this->quit = true;
        }
        else if(strcmp(input, "info") == 0) {
            cout << "System info\n";
        }
        else {

            bool m = true;
            for(int i =0; i<size; ++i)
                if(commands[i]->getName() == input){
                    commands[i]->execute(usedJsons);
                    m = false;
                }
                if(m){
                    cout<<input<<" not a valid command\n";
                    cin.clear();
                    cin.ignore(65, '\n');
                }
            }
        cout<<"\n";
    } while (!this->quit);
}

void Menu::registerCommand(const Command *cmd)
{
    commands.append(cmd);
}
