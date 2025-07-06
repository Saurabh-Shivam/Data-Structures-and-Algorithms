#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

void allTraversals(Node *root, vector<int> &pre, vector<int> &in, vector<int> &post)
{
    if (root == nullptr)
        return;

    stack<pair<Node *, int>> st;
    st.push({root, 1});

    while (!st.empty())
    {
        auto it = st.top();
        st.pop();

        // this is a part of preorder
        if (it.second == 1)
        {
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);

            if (it.first->left != nullptr)
                st.push({it.first->left, 1});
        }

        // this is a part of inorder
        else if (it.second == 2)
        {
            in.push_back(it.first->data);
            it.second++;
            st.push(it);

            if (it.first->right != nullptr)
                st.push({it.first->right, 1});
        }

        // this is a part of postorder
        else
        {
            post.push_back(it.first->data);
        }
    }
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<int> pre, in, post;
    allTraversals(root, pre, in, post);

    cout << "Preorder: ";
    for (int val : pre)
        cout << val << " ";
    cout << endl;

    cout << "Inorder: ";
    for (int val : in)
        cout << val << " ";
    cout << endl;

    cout << "Postorder: ";
    for (int val : post)
        cout << val << " ";
    cout << endl;

    return 0;
}
