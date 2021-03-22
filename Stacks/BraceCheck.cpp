#include <iostream>
#include <stack>

using namespace std;

bool checkBraces(const string &str)
{
    stack<char> aStack;
    bool balancedSoFar = true;
    int i = 0;

    char ch;

    while (balancedSoFar && i < str.length())
    {
        ch = str[i];
        if (ch == '{')
        {
            aStack.push(ch);
        }
        else if (ch == '}')
        {
            if (!aStack.empty())
            {
                aStack.pop();
            }
            else
            {
                balancedSoFar = false;
            }
        }
        i++;
    }

    return (balancedSoFar && aStack.empty());
}

int main()
{
    string str;

    str = "x{{yz}}}";

    cout << "x{{yz}}} is balance : " << boolalpha << checkBraces(str) << endl;

    str = "x{y{{z}}}";
    cout << "x{y{{z}}} is balance : " << boolalpha << checkBraces(str) << endl;

    str = "{{{x}}}";
    cout << "{{{x}}} is balance : " << boolalpha << checkBraces(str) << endl;
}