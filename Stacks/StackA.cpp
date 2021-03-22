// *********************************************************
// Implementation file StackA.cpp for the ADT Stack.
// Array-based implementation.
// *********************************************************

#include "iostream"
using namespace std;

template <typename StackItem>
Stack<StackItem> :: Stack(): top(-1)
{
}

template <typename StackItem>
bool Stack<StackItem> ::isEmpty() const
{
   return top < 0;
}

template <typename StackItem>
bool Stack<StackItem> ::push(const StackItem &newItem)
{
// if Stack has no more room for another item
   if (top >= MAX_STACK-1)
      return false;
   else
   {  
      top++;
      items[top] = newItem;
      return true;
   } 
} 

template <typename StackItem>
bool Stack<StackItem> ::pop(StackItem &StackTop)
{
   if (isEmpty())
      return false;
   else
   {  // Stack is not empty, retrieve top
      --top; // pop top
      StackTop = items[top + 1];
      return true;
   } 
} 

template <typename StackItem>
bool Stack<StackItem>::pop()
{
   if (isEmpty())
      return false;
   else
   {
      --top; // Stack< is not empty, pop top
      return true;
   }
} 

template <typename StackItem>
bool Stack<StackItem>::getTop(StackItem &StackTop) const
{
   if (isEmpty())
      return false;
   else
   {
      //  Stack is not empty; retrieve top
      StackTop = items[top];
      return true;
   }
}
