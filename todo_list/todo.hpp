#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class List
{
    private:
        std::fstream myFile;
        std::vector<std::string> list;
    public:
        
        List();
        ~List();
        void addItem(std::string item);
        void checkOff(int num);
        std::vector<std::string> getList();
        void saveList();
        void printList();
};

List::List()
{
    list = getList();
}

List::~List()
{
    saveList();
}

void List::addItem(std::string item)
{
    int itemNum = list.size()+1;
    std::string newItem = std::to_string(itemNum)+". "+item;
    list.push_back(newItem);
}

void List::checkOff(int num)
{
    
}
//Grab list from file
std::vector<std::string> List::getList()
{
    std::string item = " ";
    myFile.open("list.txt");
    if(!myFile.good())
    {
        std::cout<< "File failed to open";
        return list;
    }
    while(!myFile.eof())
    {
        getline(myFile, item);
        list.push_back(item); 
    }
    list.pop_back();
    myFile.close();
    return list;
}
void List::saveList()
{
    
}
void List::printList()
{
    std::cout << std::endl;
    std::vector<std::string>::iterator it;
    for(it = list.begin(); it != list.end(); it++)
    {
        std::cout << *it << std::endl;
    }
}
