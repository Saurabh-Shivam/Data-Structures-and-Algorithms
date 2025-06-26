#include <bits/stdc++.h>
using namespace std;

// Function to return precedence of operators
int prec(char c)
{
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

// Function to check if character is operator
bool isOperator(char c)
{
    return (!isalnum(c) && c != '(' && c != ')');
}

// Function to reverse the string and swap brackets
string reverseAndSwapBrackets(string s)
{
    reverse(s.begin(), s.end());
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
            s[i] = ')';
        else if (s[i] == ')')
            s[i] = '(';
    }
    return s;
}

// Function to convert infix to postfix
string infixToPostfix(string s)
{
    stack<char> st;
    string result;

    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];

        if (isalnum(c))
        {
            result += c;
        }
        else if (c == '(')
        {
            st.push(c);
        }
        else if (c == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                result += st.top();
                st.pop();
            }
            if (!st.empty())
                st.pop(); // Remove '('
        }
        else
        { // operator
            while (!st.empty() &&
                   ((prec(c) < prec(st.top())) ||
                    (prec(c) == prec(st.top()) && c != '^')))
            {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty())
    {
        result += st.top();
        st.pop();
    }

    return result;
}

// Function to convert infix to prefix
void infixToPrefix(string infix)
{
    cout << "Infix expression: " << infix << endl;

    // Step 1: Reverse and swap brackets
    string reversedInfix = reverseAndSwapBrackets(infix);

    // Step 2: Convert reversed infix to postfix
    string postfix = infixToPostfix(reversedInfix);

    // Step 3: Reverse postfix to get prefix
    reverse(postfix.begin(), postfix.end());

    cout << "Prefix expression: " << postfix << endl;
}

// Main
int main()
{
    string exp = "(p+q)*(m-n)";
    infixToPrefix(exp);
    return 0;
}
