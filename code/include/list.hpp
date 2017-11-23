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
    List(unsigned int _counter = 0) : counter(_counter) { }; 
   ~List() = default;
    bool insert(int value = 0);
    bool headIsEmpty() { return headList == nullptr; }
	bool headHasNextElement() { return headList->nextNode != nullptr; }
    std::shared_ptr<Node> getHead() const { return headList; }
    bool deleteElement(int index);
    int size() const { return counter; }
    void showElements() const;
    unsigned int counter;

private:
    std::shared_ptr<Node> goToEndList(const std::shared_ptr<Node> & head);   
    std::shared_ptr<Node> headList;
    int headValue() const { return headList->valueNode; }
    void deleteFirstElement();
    bool sxdeleteFirstElement(int index);
};
