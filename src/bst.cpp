#include "../include/Trees/binarysearchtree.hpp"
#include <iostream>

#include "util.hpp"

int main()
{
    BinarySearchTree<int> bst(10);

    bst.Insert(11);
    bst.Insert(14);
    bst.Insert(12);

    // Tree structure.
    //   10
    //  /  \
    // 0x  11
    //    /  \
    //   0x  14
    //      /  \
    //     12  0x
    // Note to self: Write a function for displaying the tree structure in console.

    // Peek the root node, should display 10;
    Util::Print(bst.Peek().data);
    // Peek the root's right node, should display 11.
    Util::Print(bst.Peek().right->data);
    // Peek the above node's right node, should display 14.
    Util::Print(bst.Peek().right->right->data);
    // Peek the above ^ node's left node, should display 12.
    Util::Print(bst.Peek().right->right->left->data);

    return 0;
}