#include <iostream>
#include <stack>
#include "QueueL.h"
#include <string>

using namespace std;


bool isPalindrome(string s)
{
   Stack charStack;
   Queue charQueue;

   for (int i=0; i<s.length(); i++) {
      charStack.push(s[i]);               // Assume no errors occur
      charQueue.enqueue(s[i]);
   }

   while (!charStack.isEmpty()) {
      char stackTop, queueFront;
      charStack.pop(stackTop);
      charQueue.dequeue(queueFront);
      if (stackTop != queueFront) return false;
   }

   return true;
}