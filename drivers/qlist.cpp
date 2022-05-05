#include "../include/Lists/queuelist.hpp"

#include "util.hpp"

int main()
{
    QueueList<std::string> queue;

    queue.Enqueue("Henry");
    queue.Enqueue("Sarah");
    queue.Enqueue("Sally");

    Util::Print(queue.Dequeue());

    Util::Print(queue.ToString());

    return 0;
};