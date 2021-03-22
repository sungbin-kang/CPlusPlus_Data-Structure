// *********************************************************
// Implementation file StackL.cpp for the ADT stack.
// ADT list implementation.
// *********************************************************

#include "StackL.h" // header file

template <typename StackItem>
Stack<StackItem> :: Stack()
{
}

template <typename StackItem>
bool Stack<StackItem> ::isEmpty() const
{
   return aList.isEmpty();
}

template <typename StackItem>
bool Stack<StackItem> ::push(const StackItem &newItem)
{
   return aList.insert(1, newItem);
   // It inserts the new item in the position 1,
   // and pushes back the item that was originally at position 1.
}

template <typename StackItem>
bool Stack<StackItem> ::pop(StackItem &stackTop)
{
   bool success = aList.retrieve(1, stackTop);
   if (success == false) return false;
   aList.remove(1);
   return true;
}

template <typename StackItem>
bool Stack<StackItem> ::pop()
{
   return aList.remove(1);
} 

template <typename StackItem>
bool Stack<StackItem> ::getTop(StackItem &stackTop) const
{
   return aList.retrieve(1, stackTop);
} 
