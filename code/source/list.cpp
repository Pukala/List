#include "../include/list.hpp"
#include <iostream>

bool List::insert(int value)
{
    auto newElement = std::make_shared<Node>(value); 
    
    if(headIsEmpty())
    {
        headList = newElement;
        counter++;
        return true;
    }
 	else
 	{
        auto copyHead = goToEndList(headList);
        copyHead->nextNode = newElement;
        counter++;
		return true;
    }
    return false;
}

std::shared_ptr<Node> List::goToEndList(const std::shared_ptr<Node> & head)
{
    std::shared_ptr<Node> ptr = head;
    while(ptr->nextNode)
    {
        ptr = ptr->nextNode;
    }
    return ptr;
}

bool List::deleteElement(int index)
{
    if(headIsEmpty()) { return false; }
    else if(index == 1)
    {
        deleteFirstElement();
    }


}

void List::deleteFirstElement()
{
    headList = headList->nextNode;
}



void List::showElements() const
{
    std::cout << "show\n";
    std::shared_ptr<Node> copyHead = headList;
    while(copyHead)
    {
        std::cout << copyHead->valueNode << std::endl;
        copyHead = copyHead->nextNode;
    }
}

