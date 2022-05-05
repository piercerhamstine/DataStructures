#include "../include/Trees/binarysearchtree.hpp"
#include <iostream>

#include "util.hpp"

int main()
{
    BinarySearchTree<int> bst(10);

    bst.Insert(11);
    bst.Insert(14);
    bst.Insert(12);
    bst.Insert(9);

    // Tree structure.
    //    10
    //   /  \.
    //  9    11
    // / \   / \.
    // x  x x  14
    //         /  \.
    //        12   x

    Util::Print(bst.VisualizeTree());

    BinarySearchTree<std::string> bst2("B");

    bst2.Insert("C");
    bst2.Insert("A");

    Util::Print(bst2.VisualizeTree());

    return 0;
}