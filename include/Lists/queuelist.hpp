#ifndef QUEUE_H
#define QUEUE_H

// Queue
// FIFO (First In, First Out)
// 
//
//
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

        data = head->data;
        tempNode = head;
        head = head->nextNode;

        delete tempNode;

        return data;
    };

    void Enqueue(T data)
    {
        Node<T>* newNode = new Node<T>(data);

        if(!tail)
        {
            head = tail = newNode;
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