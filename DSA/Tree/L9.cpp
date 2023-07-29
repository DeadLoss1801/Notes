#include <bits/stdc++.h>
using namespace std;
//  Iterative Pre-order
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

/*
Using stack
*/
vector<int> preOrder(Node *root)
{
    vector<int> pre;
    if (root == NULL)
        return pre;

    stack<Node *> st;
    st.push(root);

    while (!st.empty())
    {
        root = st.top();
        st.pop();

        pre.push_back(root->data);

        if (root->right != NULL)
        {
            st.push(root->right);
        }

        if (root->left != NULL)
        {
            st.push(root->left);
        }
    }
    return pre;
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->right = new Node(4);
    vector<int> ans = preOrder(root);

    for (auto i : ans)
    {
        cout << i << " ";
    }
}