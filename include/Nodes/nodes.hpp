#ifndef NODES_HPP
#define NODES_HPP

// Singly linked node. 
template<typename T>
struct ListNode
{
    ListNode(): data(nullptr), nextNode(nullptr)
    {};

    ListNode(const T& data) : data(data), nextNode(nullptr)
    {};

    ListNode<T>* nextNode;
    T data;
};

// Doubly linked node.
template<typename T>
struct ListNodeD
{
    ListNodeD(): data(nullptr), nextNode(nullptr), prevNode(nullptr)
    {};

    ListNodeD(T& data) : data(data), nextNode(nullptr), prevNode(nullptr)
    {};

    ListNodeD<T>* nextNode;
    ListNodeD<T>* prevNode;
    T data;
};

#endif