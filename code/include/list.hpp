#pragma once
#include <memory>
#include <iostream>

template<typename T>
class List
{
private:
     struct Node
    {
        Node(T value) : valueNode(value) { }
        T valueNode;
        std::shared_ptr<Node> nextNode;
    };
public:
    
    using typeNode = std::shared_ptr<Node>;
    List(unsigned int Counter = 0) : counter(Counter) { }; 
    ~List() = default;
    typeNode getHead() const { return headList; }
    int size() const { return counter; }
    void showElements() const;
    bool insert(int value);
    bool headIsEmpty() const { return headList == nullptr; }	
    bool deleteElement(int index);
    bool pop_front();
    bool pop_back();
    typeNode find(T value) const;
    
private:
    typeNode goToEndList(typeNode & head);   
    typeNode headList;
    unsigned int counter;
    int headValue() const { return headList->valueNode; } 
    bool deleteMoreThenFirstButNotLast(int index);
    bool headHasNextElement() { return headList->nextNode != nullptr; }
    
};

template<typename T>
bool List<T>::insert(int value)
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

template<typename T>
std::shared_ptr<Node> List<T>::goToEndList(typeNode & head)
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
        return pop_front();
    }
    
    else if((index > 1) && (index < counter))
    {
        return deleteMoreThenFirstButNotLast(index);
    }
    else if(index == counter)
    {
        return pop_back();
    }
}

bool List::pop_front()
{
    headList = headList->nextNode;
    counter--;
    if(headList)
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool List::deleteMoreThenFirstButNotLast(int index)
{
    unsigned int position = 0;
    std::shared_ptr<Node> copyHead = headList;
    while(copyHead->nextNode->nextNode && index <= position)
    {
        copyHead = copyHead->nextNode;
        position++;
    }
    
    copyHead->nextNode= copyHead->nextNode->nextNode;
    counter--;

    if(copyHead->nextNode)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool List::pop_back()
{
    auto copyHead = goToEndList(headList);
    copyHead = nullptr;
    counter--;
    if(copyHead)
    {
        return false;
    }
    else
    {
        return true;
    }

}

List::typeNode List::find(int value) const
{
   if(!(headList))
   {
       return nullptr;
   }
   if(headList->valueNode == value)
   {
       return headList;
   }
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

