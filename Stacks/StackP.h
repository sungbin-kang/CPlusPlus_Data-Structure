#ifndef STACK_H
#define STACK_H 

template <typename StackItem>
class Stack
{

public:

// constructors and destructor:

   Stack();                    // default constructor
   Stack(const Stack& aStack); // copy constructor
   ~Stack();                   // destructor

// stack operations:

   // Determines whether a Stack is empty.
   // Precondition: None.
   // Postcondition: Returns true if the Stack is empty; otherwise returns false.
   bool isEmpty() const;

   // Adds an item to the top of a Stack.
   // Precondition: newItem is the item to be added.
   // Postcondition: If the insertion is successful, newItem
   // is on the top of the Stack.
   // Returns true if successful, false otherwise.
   bool push(const StackItem &newItem);

   // Removes the top of a Stack.
   // Precondition: None.
   // Postcondition: If the Stack is not empty, the item
   // that was added most recently is removed. However, if
   // the Stack is empty, deletion is impossible.
   // Returns true if successful, false otherwise.
   bool pop();

   // Retrieves and removes the top of a Stack.
   // Precondition: None.
   // Postcondition: If the Stack is not empty, StackTop
   // contains the item that was added most recently and the
   // item is removed. However, if the Stack is empty,
   // deletion is impossible and StackTop is unchanged.
   // Returns true if successful, false otherwise.
   bool pop(StackItem &StackTop);

   // Retrieves the top of a Stack.
   // Precondition: None.
   // Postcondition: If the Stack is not empty, StackTop
   // contains the item that was added most recently.
   // However, if the Stack is empty, the operation fails
   // and StackTop is unchanged. The Stack is unchanged.
   // Returns true if successful, false otherwise.
   bool getTop(StackItem &StackTop) const;

private:

   struct StackNode	// a node on the stack
   {
      StackItem item;	// a data item on the stack
      StackNode *next;  // pointer to next node
   }; 

   StackNode *topPtr;	// pointer to first node in the stack
}; 

#include "StackP.cpp"

#endif
