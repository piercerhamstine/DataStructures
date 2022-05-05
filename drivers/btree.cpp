#include <iostream>

#include "../include/Trees/binarytree.hpp"

#include "util.hpp"

int main()
{
    BinaryTree b;

    b.Push(10);
    b.Push(20);
    b.Push(30);
    b.Push(40);

    Util::Print(b.Peek().left->val);
    Util::Print(b.Peek().right->val);
    
    b.Pop();
    b.Pop();

    Util::Print(b.Peek().left);
    Util::Print(b.Peek().right);
    Util::Print(b.Peek().left->left);
    
    return 0;
}
