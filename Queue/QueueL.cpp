// ********************************************************
// Implementation file QueueL.cpp for the ADT queue.
// ADT list implementation.
// ********************************************************

#include "QueueL.h" // header file
#include <iostream>
using namespace std;



template <typename QueueItem>
bool Queue<QueueItem> ::isEmpty() const
{
   return (aList.getLength() == 0);
} 


template <typename QueueItem>
bool Queue<QueueItem> ::enqueue(const QueueItem &newItem)
{
	return aList.insert(aList.getLength()+1, newItem);
	// It inserts the new item at the end of the list.
} 


template <typename QueueItem>
bool Queue<QueueItem> ::dequeue()
{
	if (aList.isEmpty())
		return false;
	else
		return aList.remove(1);
} 


template <typename QueueItem>
bool Queue<QueueItem> ::dequeue(QueueItem& queueFront)
{
	if (aList.isEmpty())
		return false;
	else
	{
		aList.retrieve(1, queueFront);
		return aList.remove(1);
	}
} 

template <typename QueueItem>
bool Queue<QueueItem> ::getFront(QueueItem& queueFront) const
{
	if (aList.isEmpty())
		return false;
	else
	{
		aList.retrieve(1, queueFront);
		return true;
	}
}
