#include <iostream>
#include <stack>

using namespace std;

bool checkMirrored(const string &str)
{
    bool soFarMirror = true;
    stack<char> aStack;

    int i = 0; 
    char ch = str[i];

    while (ch != '$')
    {
        
        aStack.push(ch);
        i++;
        ch = str[i];
    }

    i++; // skip $

    char top;
    while (soFarMirror && i < str.length())
    {
        ch = str[i];
        if (!aStack.empty())
        {
            top = aStack.top();
            aStack.pop();
            if (top == ch)
            {
                i++;
            }
            else
            {
                soFarMirror = false;
            }
        }
        else
        {
            soFarMirror = false;
        }
    }

    return soFarMirror && aStack.empty();
}

int main()
{
    string str;

    str = "a$a";
    cout << "a$a is mirror string : " << boolalpha << checkMirrored(str) << endl;

    str = "ab$ab";
    cout << "ab$ab is mirror string : " << boolalpha << checkMirrored(str) << endl;

    str = "ab$a";
    cout << "ab$a is mirror string : " << boolalpha << checkMirrored(str) << endl;

    str = "ab$ba";
    cout << "ab$ba is mirror string : " << boolalpha << checkMirrored(str) << endl;


}

/*

a$a

ab$ab

ab$a

ab$ba


*/