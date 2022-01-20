#include <iostream>

#include "util.hpp"
#include "../in/Lists/linkedlist.hpp"

int main()
{
    LinkedList<int> l1;

    l1.PushBack(1);
    l1.PushBack(2);
    l1.PushBack(3);
    
    std::cout << l1.ToString();
    // List structure
    //
    // 0 -> 1 -> 2
    //
}