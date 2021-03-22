// *********************************************************
// Implementation file QueueP.cpp for the ADT queue.
// Pointer-based implementation.
// *********************************************************

#include "QueueP.h"
#include <iostream>
using namespace std;


template <typename QueueItem>
Queue<QueueItem> :: Queue() : backPtr(nullptr), frontPtr(nullptr)
{
}

template <typename QueueItem>
Queue<QueueItem> :: Queue(const Queue& Q)
{
	if (Q.frontPtr == nullptr)
	{
		frontPtr = nullptr; // original list is empty
		backPtr = nullptr;
	}
	else
	{	// copy first node
		frontPtr = new QueueNode;
		frontPtr->item = Q.frontPtr->item;

		// copy rest of queue
		QueueNode *newPtr = frontPtr;
		for (QueueNode *origPtr = Q.frontPtr->next;
				  origPtr != nullptr;
				  origPtr = origPtr->next)
		{
			newPtr->next = new QueueNode;
			newPtr = newPtr->next;
			newPtr->item = origPtr->item;
		}
 
	newPtr->next = nullptr;
	backPtr = newPtr;
	} 
}


template <typename QueueItem>
Queue<QueueItem> ::~Queue()
{
   while (!isEmpty())
      dequeue();
}


template <typename QueueItem>
bool Queue<QueueItem> ::isEmpty() const
{
   return backPtr == nullptr;
} 


template <typename QueueItem>
bool Queue<QueueItem> ::enqueue(const QueueItem &newItem)
{
   // create a new node
   QueueNode *newPtr = new QueueNode;

   // allocation successful; set data portion of new node
   newPtr->item = newItem;
   newPtr->next = nullptr;
   // insert the new node
   if (isEmpty())
      // insertion into empty queue
      frontPtr = newPtr;
   else
      // insertion into nonempty queue
      backPtr->next = newPtr;

   backPtr = newPtr; // new node is at back
   return true;
} 

template <typename QueueItem>
bool Queue<QueueItem> ::dequeue()
{
   if (isEmpty())
      return false;
   else
   {  // queue is not empty; remove front
      QueueNode *tempPtr = frontPtr;
      if (frontPtr == backPtr) // special case?
      {  // yes, one node in queue
         frontPtr = nullptr;
         backPtr = nullptr;
      }
      else
         frontPtr = frontPtr->next;

      delete tempPtr;
      return true;
   } 
} 

template <typename QueueItem>
bool Queue<QueueItem> ::dequeue(QueueItem& queueFront)
{
   if (isEmpty())
      return false;
   else
   {  // queue is not empty; retrieve front
      queueFront = frontPtr->item;
      dequeue(); // delete front
      return true;
   } 
} 

template <typename QueueItem>
bool Queue<QueueItem> ::getFront(QueueItem& queueFront) const
{
   if (isEmpty())
      return false;
   else
      // queue is not empty; retrieve front
      queueFront = frontPtr->item;
      return true;
} 
