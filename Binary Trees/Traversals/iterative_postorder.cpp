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

    stack<Node *> s;
    Node *curr = root;
    Node *lastVisited = nullptr;

    while (curr != nullptr || !s.empty())
    {
        if (curr != nullptr)
        {
            s.push(curr);
            curr = curr->left;
        }
        else
        {
            Node *peekNode = s.top();
            // If right child exists and is not yet visited
            if (peekNode->right != nullptr && lastVisited != peekNode->right)
            {
                curr = peekNode->right;
            }
            else
            {
                res.push_back(peekNode->data);
                lastVisited = peekNode;
                s.pop();
            }
        }
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
