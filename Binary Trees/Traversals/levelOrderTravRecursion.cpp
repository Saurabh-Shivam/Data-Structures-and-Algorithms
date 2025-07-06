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

void levelOrderRec(Node *root, int level, vector<vector<int>> &res)
{
    // Base case: If node is null, return
    if (root == nullptr)
        return;

    // Add a new level to the result if needed
    if (res.size() <= level)
        res.push_back({});

    // Add current node's data to its corresponding level
    res[level].push_back(root->data);

    // Recur for left and right children
    levelOrderRec(root->left, level + 1, res);
    levelOrderRec(root->right, level + 1, res);
}

// Function to perform level order traversal
vector<vector<int>> levelOrder(Node *root)
{
    // Stores the result level by level
    vector<vector<int>> res;

    levelOrderRec(root, 0, res);
    return res;
}

int main()
{
    //      5
    //     / \
    //   12   13
    //   /  \    \
    //  7    14    2
    //  /  \   /  \  / \
    //17  23 27  3  8  11

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