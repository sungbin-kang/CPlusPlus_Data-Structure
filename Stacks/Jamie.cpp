#include <iostream>
#include <stack>

using namespace std;

int main()
{
    stack<string> aStack;
    
    aStack.push("Jill");
    aStack.push("Jane");
    aStack.push("Jamie");

    // cout << aStack.top() << endl;

    for(int i = 0; i < 3; i++)
    {
        string top = aStack.top();
        cout << top << endl;
        aStack.pop();
    }
}