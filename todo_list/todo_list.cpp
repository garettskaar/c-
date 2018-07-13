#include "todo.hpp"

int main()
{
    List list;
    list.printList();
    std::cout << "Enter a to add, r to checkoff, or q to quit."<<std::endl;
    char userInput;
    bool quit = false;
    std::cin >> userInput;
    while(!quit)
    {
        switch(userInput)
        {
            case('a'):
            {
                std::string newItem;
                std::cout << "Add: ";
                std::cin >> newItem;
                list.addItem(newItem);
                std::cout << "\nMore to add?\nenter a,r or q...\n";
                std::cin >> userInput;
                break;
            }
            case('r'):
            {
                std::cout << "Checkoff: ";
                break;
            }
            case('q'):
                list.printList();
                quit = true;
                break;
            default: 
                std::cout << "Enter a to add, r to checkoff, or q to quit."<<std::endl;
            }
    }
    return 0;
}
