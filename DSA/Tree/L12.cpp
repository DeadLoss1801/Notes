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
Using  1 stack
*/
vector<int> postOrder(Node *root)
{
    vector<int> post;
    stack<Node *> st;

    while (root != NULL || !st.empty())
    {
        if (root != NULL)
        {
            st.push(root);
            root = root->left;
        }
        else
        {
            Node *node = st.top()->right;
            if (node == NULL)
            {
                node = st.top();
                st.pop();
                post.push_back(node->data);
                while (!st.empty() && node == st.top()->right)
                {
                    node = st.top();
                    st.pop();
                    post.push_back(node->data);
                }
            }
            else
            {
                root = node;
            }
        }
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