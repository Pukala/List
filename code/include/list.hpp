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
    List() = default;
   ~List() = default;
    bool insert(int value = 0);
    bool headIsEmpty() { return headList == nullptr; }
    std::shared_ptr<Node> getHead() const { return headList; }
private:
    std::shared_ptr<Node> headList;
};
