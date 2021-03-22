#include <iostream>
#include <stack>

using namespace std;

bool isFrontBrace(const char ch)
{
    switch (ch)
    {
    case '[':
        return true;
        break;
    case '{':
        return true;
        break;
    case '(':
        return true;
        break;
    default:
        return false;
    }
}

bool isBackBrace(const char ch)
{
    switch (ch)
    {
    case ']':
        return true;
        break;
    case '}':
        return true;
        break;
    case ')':
        return true;
        break;
    default:
        return false;
    }
}

bool isMatching(const char ch1, const char ch2)
{
    switch (ch1)
    {
    case '[':
        return ch2 == ']';
        break;
    case '{':
        return ch2 == '}';
        break;
    case '(':
        return ch2 == ')';
        break;
    default:
        return false;
    }
}

bool balanceBraceCheck(const string str)
{
    stack<char> braces;
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        if (isFrontBrace(ch))
        {
            braces.push(ch);
        }
        else if (isBackBrace(ch))
        {
            char front = braces.top();
            if (!isMatching(front, ch))
            {
                return false;
            }
            else
            {
                braces.pop();
            }

        }
    }
    return true;
}

int main()
{
    string str;

    str = "{ab(c[d])e}";

    balanceBraceCheck(str) ? str += " braces are balacned." : str += " braces are NOT balacned" ;
    cout << str << endl;

    str = "{ab(c))";

    balanceBraceCheck(str) ? str += " braces are balacned." : str += " braces are NOT balacned" ;
    cout << str << endl;
    
}