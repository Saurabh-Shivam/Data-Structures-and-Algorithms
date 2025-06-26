#include <bits/stdc++.h>
using namespace std;

// Function to check if a character is an operator
bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Function to convert Prefix to Infix
void prefixToInfix(string prefix)
{
    stack<string> st;

    // Traverse from right to left
    for (int i = prefix.length() - 1; i >= 0; i--)
    {
        char c = prefix[i];

        // If operand, push to stack
        if (isalnum(c))
        {
            string op(1, c);
            st.push(op);
        }
        // If operator, pop two operands and form new infix expression
        else if (isOperator(c))
        {
            if (st.size() < 2)
            {
                cout << "Invalid prefix expression\n";
                return;
            }

            string op1 = st.top(); st.pop(); // Left operand
            string op2 = st.top(); st.pop(); // Right operand

            string expr = "(" + op1 + c + op2 + ")";
            st.push(expr);
        }
    }

    // Final result
    if (st.size() == 1)
        cout << "Infix expression: " << st.top() << endl;
    else
        cout << "Invalid prefix expression\n";
}

int main()
{
    string prefix = "*+pq-mn";
    cout << "Prefix expression: " << prefix << endl;
    prefixToInfix(prefix);
    return 0;
}
