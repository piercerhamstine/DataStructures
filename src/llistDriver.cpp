#include <iostream>

#include "util.hpp"
#include "../include/Lists/linkedlist.hpp"

int main()
{
    LinkedList<int> l1;

    // List structure
    //
    // 0 -> 1 -> 2
    //

    l1.PushBack(0);
    l1.PushBack(1);
    l1.PushBack(2);

    std::cout << l1.ToString() << std::endl;

    // List structure
    //
    // 3 -> 0 -> 1 -> 2
    //

    l1.PushFront(3);
    std::cout << l1.ToString() << std::endl;

    l1.RemoveAt(3);
    std::cout << l1.ToString();
}