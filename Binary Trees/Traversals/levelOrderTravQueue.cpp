#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;

    // Constructor to initialize a new node
    Node(int value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Iterative method to perform level order traversal
vector<vector<int>> levelOrder(Node *root)
{
    if (root == nullptr)
        return {};

    // Create an empty queue for level order traversal
    queue<Node *> q;
    vector<vector<int>> res;

    // Enqueue Root
    q.push(root);
    int currLevel = 0;

    while (!q.empty())
    {
        int len = q.size();
        res.push_back({});

        for (int i = 0; i < len; i++)
        {

            // Add front of queue and remove it from queue
            Node *node = q.front();
            q.pop();

            res[currLevel].push_back(node->data);

            // Enqueue left child
            if (node->left != nullptr)
                q.push(node->left);

            // Enqueue right child
            if (node->right != nullptr)
                q.push(node->right);
        }
        currLevel++;
    }
    return res;
}

int main()
{
    //      5
    //     / \
    //   12   13
    //   /  \    \
    //  7    14   2
    //  /  \   /  \  / \
    //17 23 27  3  8  11

    Node *root = new Node(5);
    root->left = new Node(12);
    root->right = new Node(13);

    root->left->left = new Node(7);
    root->left->right = new Node(14);

    root->right->right = new Node(2);

    root->left->left->left = new Node(17);
    root->left->left->right = new Node(23);

    root->left->right->left = new Node(27);
    root->left->right->right = new Node(3);

    root->right->right->left = new Node(8);
    root->right->right->right = new Node(11);

    vector<vector<int>> res = levelOrder(root);

    for (vector<int> level : res)
    {
        cout << "[";
        for (int i = 0; i < level.size(); i++)
        {
            cout << level[i];
            if (i < level.size() - 1)
                cout << ", ";
        }
        cout << "] ";
    }

    return 0;
}