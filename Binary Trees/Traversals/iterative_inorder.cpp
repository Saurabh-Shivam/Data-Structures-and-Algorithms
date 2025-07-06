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

vector<int> inOrder(Node *root)
{
    vector<int> res;
    stack<Node *> s;
    Node *curr = root;

    while (curr != nullptr || !s.empty())
    {
        while (curr != nullptr)
        {
            s.push(curr);
            curr = curr->left;
        }

        curr = s.top();
        s.pop();
        res.push_back(curr->data);

        curr = curr->right;
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

    vector<int> inorder = inOrder(root);

    for (int val : inorder)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
