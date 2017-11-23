#include <iostream>
#include "code/include/list.hpp"

int main()
{
    List x;
    x.insert(1);
    x.insert(2);
    x.insert(3);
    x.insert(4);
    x.showElements();
    std::cout << x.getHead()->valueNode << std::endl;
    std::cout << x.getHead()->nextNode->valueNode << std::endl;
    std::cout << x.getHead()->nextNode->nextNode->valueNode << std::endl;
    std::cout << x.getHead()->nextNode->nextNode->nextNode->valueNode << std::endl;
}
