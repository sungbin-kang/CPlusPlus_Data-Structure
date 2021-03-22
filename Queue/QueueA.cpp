// ********************************************************
// Implementation file QueueA.cpp for the ADT queue.
// Circular array-based implementation.
// The array has indexes to the front and back of the
// queue. A counter tracks the number of items currently
// in the queue.
// ********************************************************

#include "QueueA.h"
#include <iostream>
using namespace std;

template <typename QueueItem>
Queue<QueueItem> :: Queue():front(0), back(MAX_QUEUE-1), count(0)
{
}

template <typename QueueItem>
bool Queue<QueueItem> ::isEmpty() const
{
   return count == 0;
}

template <typename QueueItem>
bool Queue<QueueItem> ::enqueue(const QueueItem &newItem)
{
   if (count == MAX_QUEUE)
      return false;
   else
   {  // queue is not full; insert item
      back = (back+1) % MAX_QUEUE;
      items[back] = newItem;
      count++;
      return true;
   } 
} 

template <typename QueueItem>
bool Queue<QueueItem> ::dequeue()
{
   if (isEmpty())
      return false;
   else
   {  // queue is not empty; remove front
      front = (front+1) % MAX_QUEUE;
      count--;
      return true;
   } 
} 

template <typename QueueItem>
bool Queue<QueueItem> ::dequeue(QueueItem &queueFront)
{
   if (isEmpty())
      return false;
   else
   {  // queue is not empty; retrieve and remove front
      queueFront = items[front];
      front = (front+1) % MAX_QUEUE;
      count--;
      return true;
   } 
} 

template <typename QueueItem>
bool Queue<QueueItem> ::getFront(QueueItem& queueFront) const
{
   if (isEmpty())
       return false;
   else
      //  queue is not empty; retrieve front
      queueFront = items[front];
      return true;
}
