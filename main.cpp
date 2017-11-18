#include <iostream>
#include "code/include/list.hpp"

int main()
{
    List x;
    x.insert(4);
    std::cout << x.getHead()->valueNode << std::endl;
}
