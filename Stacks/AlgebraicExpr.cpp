#include <iostream>
#include <stack>
#include <cctype>

using namespace std;

int compute(int a, int b, char op)
{
    int i = 0;
    switch (op)
    {

    case '+':
        i = a + b;
        break;
    case '-':
        i = a - b;
        break;
    case '*':
        i = a * b;
        break;
    case '/':
        i = a / b;
        break;
    case '%':
        i = a % b;
        break;
    case '^':
        i = a ^ b;
        break;
    default:
        i = 0;
    }
    return i;
}

/*
Assumption
• The string is a syntactically correct postfix expression
• No unary operators are present
• No exponentiation operators are present
• Operands are single lowercase letters that represent integer values

2 * ( 3 + 4 )
postfix:
2 3 4 + *

14
*/
int evaluatePostFixExp(const string &expr)
{
    int total;

    stack<int> operands;
    int operator1;
    int operator2;

    for (int i = 0; i < expr.length(); i++)
    {
        if (isdigit(expr[i]))
        {
            operands.push(expr[i] - 48);
        }
        else // operator ch
        {
            operator2 = operands.top();
            operands.pop();

            operator1 = operands.top();
            operands.pop();

            total = compute(operator1, operator2, expr[i]);
            operands.push(total);
        }
    }
    return total;
}

bool isOperator(char ch)
{
    switch (ch)
    {
    case '+':
        return true;
        break;
    case '-':
        return true;
        break;
    case '*':
        return true;
        break;
    case '/':
        return true;
        break;
    case '%':
        return true;
        break;
    case '^':
        return true;
        break;
    default:
        return false;
    }
}

/**
 * Pre: the expression meets proper infix condition
 * with operators and operands with character without any space.
 * Post: postfix string expression
 * 
 * Detects braces, but operator precedence are not followed.
 * 
 * ex)
 * a-b+c => ab-
 * 
 */
string inToPostfix(const string expr)
{
    stack<char> operators;

    string str = "";

    int i = 0;
    str += expr[i];
    i++;
    while (i < expr.length())
    {
        operators.push(expr[i]);
        i++;
        if (expr[i] == '(')
        {
            i++;
            str += expr[i];
            i++;
            while (expr[i] != ')')
            {
                operators.push(expr[i]);
                i++;
                str += expr[i];
                i++;
                str += operators.top();
                operators.pop();
            }
            i++;
        }
        str += expr[i];
        i++;
        str += operators.top();
        operators.pop();
    }

    return str;
}

int main()
{
    string postExpr;

    postExpr = "234+*";
    cout << postExpr << " = " << evaluatePostFixExp(postExpr) << endl;

    string infixExpr;

    infixExpr = "a-b+c";
    cout << inToPostfix(infixExpr) << endl;

    infixExpr = "a-(b/c*d)";
    cout << inToPostfix(infixExpr) << endl;

    infixExpr = "a/(b*c)";
    cout << inToPostfix(infixExpr) << endl;

    infixExpr = "a/b/c-(d+e)*f";
    cout << inToPostfix(infixExpr) << endl;

    infixExpr = "a-(b+c*d)/e";
    cout << inToPostfix(infixExpr) << endl;
}
