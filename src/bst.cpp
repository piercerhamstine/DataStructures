#include "../include/Trees/binarysearchtree.hpp"
#include <iostream>

int main()
{
    BinarySearchTree<int> bst(10);

    std::cout << bst.Peek().data;

    return 0;
}