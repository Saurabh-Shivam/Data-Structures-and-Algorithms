#include <bits/stdc++.h>
using namespace std;

// Function to check if a character is an operator
bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Function to return precedence of operators
int precedence(char c)
{
    if (c == '^')
        return 3;
    if (c == '*' || c == '/')
        return 2;
    if (c == '+' || c == '-')
        return 1;
    return -1;
}

// Function to convert Infix to Prefix
string infixToPrefix(string infix)
{
    // Reverse the infix expression
    reverse(infix.begin(), infix.end());

    // Swap '(' with ')' and vice versa
    for (int i = 0; i < infix.length(); i++)
    {
        if (infix[i] == '(')
            infix[i] = ')';
        else if (infix[i] == ')')
            infix[i] = '(';
    }

    stack<char> st;
    string result;

    for (int i = 0; i < infix.length(); i++)
    {
        char c = infix[i];

        // If operand, add to result
        if (isalnum(c))
        {
            result += c;
        }
        // If '(', push to stack
        else if (c == '(')
        {
            st.push(c);
        }
        // If ')', pop until '('
        else if (c == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                result += st.top();
                st.pop();
            }
            if (!st.empty())
                st.pop(); // pop '('
        }
        // If operator
        else if (isOperator(c))
        {
            while (!st.empty() && precedence(st.top()) > precedence(c) ||
                   (precedence(st.top()) == precedence(c) && c != '^'))
            {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    // Pop remaining operators
    while (!st.empty())
    {
        result += st.top();
        st.pop();
    }

    // Reverse the result to get prefix
    reverse(result.begin(), result.end());

    return result;
}

int main()
{
    string infix = "((p+q)*(m-n))";
    cout << "Infix expression: " << infix << endl;
    string prefix = infixToPrefix(infix);
    cout << "Prefix expression: " << prefix << endl;
    return 0;
}
