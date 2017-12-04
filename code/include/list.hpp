#pragma once
#include <memory>

struct Node
{
    Node(int value) : valueNode(value) { }
    int valueNode;
    std::shared_ptr<Node> nextNode;
};

class List
{
public:
    using typeNode = std::shared_ptr<Node>;
    
    List(unsigned int Counter = 0) : counter(Counter) { }; 
   ~List() = default;
    typeNode getHead() const { return headList; }
    int size() const { return counter; }
    void showElements() const;
    bool insert(int value = 0);
    bool headIsEmpty() const { return headList == nullptr; }	
    bool deleteElement(int index);
    bool pop_front();
    bool pop_back();
    typeNode find(int value) const;
    

private:
    typeNode goToEndList(typeNode & head);   
    typeNode headList;
    unsigned int counter;
    int headValue() const { return headList->valueNode; } 
    bool deleteMoreThenFirstButNotLast(int index);
    bool headHasNextElement() { return headList->nextNode != nullptr; }
};
