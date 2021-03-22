#pragma once
#include <iostream>

using namespace std;

template <typename QueueItem>
class Queue
{
    friend class QueueTest;

public:
    bool dequeueBack();

private:
    struct QueueNode
    {
        QueueItem item;
        QueueNode *next;
    };
    QueueNode *frontPtr;
    QueueNode *backPtr;
};