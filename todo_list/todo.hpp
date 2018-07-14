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
        int getSize();
};

List::List()
{
    list = getList();
}

List::~List()
{
    saveList();
}
int List::getSize()
{
    return list.size();
}
void List::addItem(std::string item)
{
    list.push_back(item);
}

void List::checkOff(int num)
{
    //Deal with 0 start indexing
    num = num - 1;
    list.erase(list.begin() + num);
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
    int i = 0;
    for(it = list.begin(); it != list.end(); it++)
    {
        i++;
        std::cout << i << ". " << *it << std::endl;
    }
}
