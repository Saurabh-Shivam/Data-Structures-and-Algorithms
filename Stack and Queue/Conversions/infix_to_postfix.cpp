#include <bits/stdc++.h>
using namespace std;

int prec(char c) {
  if (c == '^')
    return 3;
  else if (c == '/' || c == '*')
    return 2;
  else if (c == '+' || c == '-')
    return 1;
  else
    return -1;
}

void infixToPostfix(string s) {
  stack < char > st;
  string result;

  for (int i = 0; i < s.length(); i++) {
    char c = s[i];

    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
      result += c;

    else if (c == '(')
      st.push('(');

    else if (c == ')') {
      while (!st.empty() && st.top() != '(') {
        result += st.top();
        st.pop();
      }
      if (!st.empty()) st.pop(); // Remove '('
    }

    else {
      while (!st.empty() && 
             ((prec(c) < prec(st.top())) || 
             (prec(c) == prec(st.top()) && c != '^'))) {
        result += st.top();
        st.pop();
      }
      st.push(c);
    }
  }

  while (!st.empty()) {
    result += st.top();
    st.pop();
  }

  cout << "Postfix expression: " << result << endl;
}

int main() {
  string exp = "(p+q)*(m-n)";
  cout << "Infix expression: " << exp << endl;
  infixToPostfix(exp);
  return 0;
}
