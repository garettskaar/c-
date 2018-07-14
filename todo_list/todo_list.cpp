#include "todo.hpp"

int main()
{
    List list;
    list.printList();
    std::cout <<std::endl<< "Enter a to add, r to checkoff, or q to quit."<<std::endl;
    char userInput;
    bool quit = false;
    while(!quit)
    {
        std::cin >> userInput;
        switch(userInput)
        {
            case('a'):
            {
                std::string newItem;
                std::cout << "Add: ";
                std::cin >> newItem;
                list.addItem(newItem);
                list.printList();
                std::cout << "\nEnter a to add, r to checkoff, or q to quit.\n";
                break;
            }
            case('r'):
            {
                if(list.getSize() == 0)
                {
                    std::cout << "Nothing in your list to remove.";
                    std::cout << "\nEnter a to add or q to quit.\n";
                    break;
                }
                int itemNum = 0;
                while(itemNum <= 0 || (itemNum > list.getSize()))
                {
                    std::cout << "Enter item number: ";
                    std::cin >> itemNum;
                    //Ensures an integer is entered.
                    while(std::cin.fail())
                    {
                        std::cout << "Enter item number: ";
                        std::cin.clear();
                        std::cin.ignore(256,'\n');
                        std::cin >> itemNum;
                    }
                }
                list.checkOff(itemNum);
                list.printList();
                std::cout << "\nEnter a to add, r to checkoff, or q to quit.\n";
                break;
            }
            case('q'):
            {
                list.printList();
                quit = true;
                break;
            }
            default:
            {
                list.printList();
                std::cout << "Enter a to add, r to checkoff, or q to quit."<<std::endl;
                break;
            }
        }
    }
    return 0;
}
