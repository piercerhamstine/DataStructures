
#include "../include/Lists/linkedlist.hpp"
#include "util.hpp"

int main()
{
    LinkedList<int> l1;

    // List structure
    //
    // 0 -> 1 -> 2
    //
    
    l1.Insert(0);
    l1.Insert(1);
    l1.Insert(2);

    Util::Print(l1.ToString());
}