#include "../include/list.hpp"

bool List::insert(int value)
{
    std::shared_ptr<Node> newElement = std::make_shared<Node>(value); 
    
    if(headIsEmpty())
    {
        headList = newElement;
        return true;
    }
 	else
 	{
        std::shared_ptr<Node> copyHead = headList;
        while(copyHead->nextNode)
        {
            copyHead = copyHead->nextNode;
        }
        copyHead->nextNode = newElement;
		return true;
    } 
}
