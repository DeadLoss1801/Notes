#include <bits/stdc++.h>
using namespace std;
//  Iterative In-order
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
vector<int> inOrder(Node *root)
{
    vector<int> in;

    stack<Node *> st;

    while (true)
    {
        if (root != NULL)
        {
            st.push(root);
            root = root->left;
        }
        else
        {
            if (st.empty())
                break;
            root = st.top();
            st.pop();
            in.push_back(root->data);
            root = root->right;
        }
    }
    return in;
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->right = new Node(4);
    vector<int> ans = inOrder(root);

    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
}