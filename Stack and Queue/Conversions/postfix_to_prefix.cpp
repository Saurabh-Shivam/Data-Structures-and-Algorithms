#include <bits/stdc++.h>
using namespace std;

// Function to check if a character is an operator
bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Function to convert Postfix to Prefix
void postfixToPrefix(string postfix)
{
    stack<string> st;

    for (int i = 0; i < postfix.length(); i++)
    {
        char c = postfix[i];

        // If operand, push to stack
        if (isalnum(c))
        {
            string op(1, c);
            st.push(op);
        }
        // If operator, pop two operands and form new prefix expression
        else if (isOperator(c))
        {
            if (st.size() < 2)
            {
                cout << "Invalid postfix expression\n";
                return;
            }

            string op2 = st.top();
            st.pop(); // Right operand
            string op1 = st.top();
            st.pop(); // Left operand

            string expr = c + op1 + op2; // Prefix form
            st.push(expr);
        }
    }

    // Final result
    if (st.size() == 1)
        cout << "Prefix expression: " << st.top() << endl;
    else
        cout << "Invalid postfix expression\n";
}

int main()
{
    string postfix = "pq+mn-*";
    cout << "Postfix expression: " << postfix << endl;
    postfixToPrefix(postfix);
    return 0;
}
