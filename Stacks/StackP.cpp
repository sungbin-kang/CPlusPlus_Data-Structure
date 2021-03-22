// *********************************************************
// Implementation file StackP.cpp for the ADT stack.
// Pointer-based implementation.
// *********************************************************

#include "StackP.h" // header file
#include <iostream> // for cout
using namespace std;

template <typename StackItem>
Stack<StackItem> :: Stack() : topPtr(nullptr)
{
}


template <typename StackItem>
Stack<StackItem> :: Stack(const Stack& aStack)
{
   if (aStack.topPtr == nullptr)
      topPtr = nullptr; // original list is empty

   else
   {  // copy first node
      topPtr = new StackNode;
      topPtr->item = aStack.topPtr->item;

      // copy rest of list
      StackNode *newPtr = topPtr; // new list pointer
      for (StackNode *origPtr = aStack.topPtr->next;
                      origPtr != nullptr;
                      origPtr = origPtr->next)
      {  newPtr->next = new StackNode;
         newPtr = newPtr->next;
         newPtr->item = origPtr->item;
      } 

   newPtr->next = nullptr;
   } 
} 


template <typename StackItem>
Stack<StackItem> ::~Stack()
{
   // pop until stack is empty
   while (!isEmpty())
      pop();
} 


template <typename StackItem>
bool Stack<StackItem> ::isEmpty() const
{
   return topPtr == nullptr;
} 


template <typename StackItem>
bool Stack<StackItem> ::push(const StackItem &newItem)
{
   // create a new node
   StackNode *newPtr = new StackNode;
   newPtr->item = newItem;
   
   // insert the new node
   newPtr->next = topPtr;
   topPtr = newPtr;
   return true;
} 


template <typename StackItem>
bool Stack<StackItem> ::pop(StackItem& stackTop)
{
   if (isEmpty())
      return false;
   else
   {  // stack is not empty; retrieve and delete top
      stackTop = topPtr->item;
      StackNode *temp = topPtr;
      topPtr = topPtr->next;

      // return deleted node to system
      temp->next = nullptr; // safeguard
      delete temp;
      return true;
   }
}


template <typename StackItem>
bool Stack<StackItem> ::pop()
{
   if (isEmpty())
       return false;
   else
   {  // stack is not empty; delete top
      StackNode *temp = topPtr;
      topPtr = topPtr->next;

      // return deleted node to system
      temp->next = nullptr; // safeguard
      delete temp;
      return true;
   } 
} 


template <typename StackItem>
bool Stack<StackItem> ::getTop(StackItem& stackTop) const
{
   if (isEmpty())
      return false;
   else
   {
      // stack is not empty; retrieve top
      stackTop = topPtr->item;
      return true;
   }
} 
