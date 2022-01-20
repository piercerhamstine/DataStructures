#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

// Linked list, 
// Nodes hold a pointer to the next node in the list, forming a chain.
// Nodes connections cannot go backwards.
//

/* TODO:
 - Sort list
 - InsertAt node
 - Deconstructor
 - Copy Constructor
*/

#include <iostream>
#include <sstream>
#include "../Nodes/nodes.hpp"

template<typename T>
class LinkedList
{
public:
    LinkedList() : head(nullptr)
    {};

    LinkedList(T data) : head(data)
    {};

    // Adds a node in front of specified node.
    void AddNodeInfront(ListNode<T>* anchorNode, ListNode<T>* nodeAdded)
    {
        // List isn't empty.
        if(head)
        {
            // The head of the list, is the anchorNode
            if(head == anchorNode)
            {
                nodeAdded->nextNode = anchorNode;
                head = nodeAdded;

                return;
            };

            // Set up temp node, search for anchor node.
            ListNode<T>* temp = head;
            while(temp)
            {
                // Node before anchor found.
                if(temp->nextNode == anchorNode)
                {
                    // Link new node to current node and anchor node. Leave loop.
                    temp->nextNode = nodeAdded;
                    nodeAdded->nextNode = anchorNode;

                    return;
                }

                temp = temp->nextNode;
            }
        }
        // List is empty
        else
        {
            // Set head and tail
            head = nodeAdded;
            tail = nodeAdded;

            // Clear nextNodes of head and tail.
            head->nextNode = nullptr;
            tail->nextNode = nullptr;
        }
    };

    void AddNodeBehind(ListNode<T>* anchorNode, ListNode<T>* nodeAdded)
    {
        if(head)
        {
            nodeAdded->nextNode = anchorNode->nextNode;
            anchorNode->nextNode = nodeAdded;

            // Check if tail pointer needs to be updated.
            if(anchorNode == tail)
            {
                tail = nodeAdded;
            }
        }
        else
        {
            head = nodeAdded;
            tail = nodeAdded;

            head->nextNode = nullptr;
            tail->nextNode = nullptr;
        }
    };

    // Adds a new node to the front of the list.
    void PushFront(const T& data)
    {
        // Create a new node.
        ListNode<T>* newNode = new ListNode<T>(data);

        // Add node to the front of the list.
        AddNodeInfront(head, newNode);
    };

    // Adds a new node to the back of the list.
    void PushBack(const T& data)
    {
        // Create a new node.
        ListNode<T>* newNode = new ListNode<T>(data);

        AddNodeBehind(tail, newNode);
        // Add node to the back of the list.
    };

    // Removes specified node from the list.
    void Remove(ListNode<T>* data)
    {

    };

    // Removes a node at a specific list index.
    void RemoveAt(int ndx)
    {

    }
    
    std::string ToString()
    {
        std::stringstream stringStream;

        ListNode<T>* currNode = head;

        while(currNode)
        {
            stringStream << currNode->data << " ";
            currNode = currNode->nextNode;
        };
        
        return stringStream.str();
    };

private:
    ListNode<T>* head;
    ListNode<T>* tail;
};

#endif