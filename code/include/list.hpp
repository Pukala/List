#pragma once
#include <memory>
#include <iostream>

template<typename T>
struct Node
{
    Node(T value) : valueNode(value) { }
    T valueNode;
    std::shared_ptr<Node> nextNode;
};

template<typename T>
class List
{
public:
    List(unsigned int Counter = 0) : counter(Counter) { }; 
    ~List() = default;
    std::shared_ptr<Node<T>> getHead() const { return headList; }
    int size() const { return counter; }
    void showElements() const;
    bool insert(T value);
    bool headIsEmpty() const { return headList == nullptr; }	
    bool deleteElement(int index);
    bool pop_front();
    bool pop_back();
    std::shared_ptr<Node<T>> find(T value) const;
    
private:
    std::shared_ptr<Node<T>> goToEndList(std::shared_ptr<Node<T>> & head);   
    std::shared_ptr<Node<T>> headList;
    unsigned int counter;
    int headValue() const { return headList->valueNode; } 
    bool deleteMoreThenFirstButNotLast(int index);
    bool headHasNextElement() { return headList->nextNode != nullptr; }
    
};

template<typename T>
bool List<T>::insert(T value)
{
    auto newElement = std::make_shared<Node<T>>(value); 
    
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
std::shared_ptr<Node<T>> List<T>::goToEndList(std::shared_ptr<Node<T>> & head)
{
    std::shared_ptr<Node<T>> ptr = head;
    while(ptr->nextNode)
    {
        ptr = ptr->nextNode;
    }
    return ptr;
}

template<typename T>
bool List<T>::deleteElement(int index)
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

template<typename T>
bool List<T>::pop_front()
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

template<typename T>
bool List<T>::deleteMoreThenFirstButNotLast(int index)
{
    unsigned int position = 0;
    std::shared_ptr<Node<T>> copyHead = headList;
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

template<typename T>
bool List<T>::pop_back()
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

template<typename T>
std::shared_ptr<Node<T>> List<T>::find(T value) const
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

template<typename T>
void List<T>::showElements() const
{
    std::cout << "show\n";
    std::shared_ptr<Node<T>> copyHead = headList;
    while(copyHead)
    {
        std::cout << copyHead->valueNode << std::endl;
        copyHead = copyHead->nextNode;
    }
}


