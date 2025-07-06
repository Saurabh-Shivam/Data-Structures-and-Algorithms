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

vector<int> preOrder(Node *root)
{
    vector<int> res;
    if (root == nullptr)
        return res;

    stack<Node *> s;
    s.push(root);

    while (!s.empty())
    {
        Node *curr = s.top();
        s.pop();
        res.push_back(curr->data);

        if (curr->right != nullptr)
            s.push(curr->right);
        if (curr->left != nullptr)
            s.push(curr->left);
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

    vector<int> preorder = preOrder(root);

    for (int val : preorder)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}