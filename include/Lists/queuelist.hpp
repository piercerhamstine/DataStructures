#ifndef QUEUE_H
#define QUEUE_H

// Queue
// FIFO (First In, First Out)
// Nodes pushed to the queue are appended to the back
// Nodes popped from the queue are always taken from the front
//

#include <string>
#include <sstream>

template<typename T>
struct Node
{
    Node()
    {
        this->data = nullptr;
        this->nextNode = nullptr;
    };

    Node(T data)
    {
        this->data = data;
        nextNode = nullptr;
    };

    T data;
    Node* nextNode;
};

template<typename T>
class QueueList
{
public:
    QueueList()
    {
        head = tail = nullptr;
    };

    T Dequeue()
    {
        T data;
        Node<T>* tempNode = nullptr;

        if(!head)
        {
            return data;
        };

        // Store the data of the head and move head to the next node.
        data = head->data;
        tempNode = head;
        head = head->nextNode;

        // Free allocated memory from heap.
        delete tempNode;
        return data;
    };

    void Enqueue(T data)
    {
        Node<T>* newNode = new Node<T>(data);

        if(!tail)
        {
            head = tail = newNode;
            return;
        }

        tail->nextNode = newNode;
        tail = tail->nextNode;
    };

    T Peek()
    {
        if(!head)
        {
            return T();
        }

        return head->data;
    };

    std::string ToString()
    {
        std::ostringstream oss;
        Node<T>* temp;

        if(!head)
        {
            return oss.str();
        };

        temp = head;

        while(temp)
        {
            oss << temp->data << " ";

            temp = temp->nextNode;
        };

        return oss.str();
    }
private:
    Node<T>* head;
    Node<T>* tail;
};

#endif