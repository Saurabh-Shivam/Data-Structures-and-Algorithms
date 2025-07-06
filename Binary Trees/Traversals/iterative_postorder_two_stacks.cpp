#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int x)
    {
        data = x;
        left = right = nullptr;
    }
};

vector<int> postOrder(Node *root)
{
    vector<int> res;
    if (root == nullptr)
        return res;

    stack<Node *> s1, s2;
    s1.push(root);

    while (!s1.empty())
    {
        Node *curr = s1.top();
        s1.pop();
        s2.push(curr);

        if (curr->left != nullptr)
            s1.push(curr->left);
        if (curr->right != nullptr)
            s1.push(curr->right);
    }

    while (!s2.empty())
    {
        res.push_back(s2.top()->data);
        s2.pop();
    }

    return res;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<int> postorder = postOrder(root);

    for (int val : postorder)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
