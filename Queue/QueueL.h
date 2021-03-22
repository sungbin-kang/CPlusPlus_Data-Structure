#pragma once

// ********************************************************
// Header file QueueP.h for the ADT queue.
// ADT List implementation.
// ********************************************************
#include "List.h"

template <typename QueueItem>
class Queue
{
public:

// constructors and destructor:

//   Queue();               // default constructor
//   Queue(const Queue& Q); // copy constructor
//  ~Queue();              // destructor

// Queue operations:

   // Determines whether the queue is empty.
   // Precondition: None.
   // Postcondition: Returns true if the queue is empty;
   // otherwise returns false.
   bool isEmpty() const;
  
   // Inserts an item at the back of a queue.
   // Precondition: newItem is the item to be inserted.
   // Postcondition: If the insertion is successful, newItem
   // is at the back of the queue.
   // Returns false if newItem cannot
   // be placed on the queue, true otherwise.
   bool enqueue(const QueueItem &newItem);

   // Dequeues the front of a queue.
   // Precondition: None.
   // Postcondition: If the queue is not empty, the item
   // that was added to the queue earliest is deleted.
   // Returns false if the queue is
   // empty, true otherwise.
   bool dequeue();

   // Retrieves and deletes the front of a queue.
   // Precondition: None.
   // Postcondition: If the queue is not empty, queueFront
   // contains the item that was added to the queue
   // earliest, and the item is deleted.
   // Returns false if the queue is
   // empty, true otherwise.
   bool dequeue(QueueItem &queueFront);

   // Retrieves the item at the front of a queue.
   // Precondition: None.
   // Postcondition: If the queue is not empty, queueFront
   // contains the item that was added to the queue
   // earliest.
   // Returns true if the queue is
   // empty, false otherwise.
   bool getFront(QueueItem &queueFront) const;

private:

   List<QueueItem> aList;	 // list of queue items

}; 

#include "QueueL.cpp"
