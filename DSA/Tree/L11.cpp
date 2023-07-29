#include <bits/stdc++.h>
using namespace std;
//  Iterative post-order
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
Using  2 stack
*/
vector<int> postOrder(Node *root)
{
    vector<int> post;
    if (root == NULL)
        return post;

    stack<Node *> st, st2;
    st.push(root);

    while (!st.empty())
    {
        root = st.top();
        st.pop();

        st2.push(root);
        if (root->left != NULL)
        {
            st.push(root->left);
        }

        if (root->right != NULL)
        {
            st.push(root->right);
        }
    }

    while (!st2.empty())
    {
        post.push_back(st2.top()->data);
        st2.pop();
    }
    return post;
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->right = new Node(4);
    vector<int> ans = postOrder(root);

    for (auto i : ans)
    {
        cout << i << " ";
    }
}