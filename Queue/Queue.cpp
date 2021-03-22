#include "Queue.h"

template <typename QueueItem>
bool Queue<QueueItem>::dequeueBack()
{
    if (frontPtr == nullptr && backPtr == nullptr)
    {
        return false;
    }

    if (frontPtr == backPtr)
    {
        delete frontPtr;
        frontPtr = nullptr;
        backPtr = nullptr;
    }
    else
    {
        QueueNode *temp = frontPtr;
        while (temp->next != backPtr)
        {
            temp = temp->next;
        }
        backPtr = temp;
        temp = temp->next;
        delete temp;
        assert(backPtr->next == nullptr);
    }

    return true;
}
