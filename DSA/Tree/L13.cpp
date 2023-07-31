#include <bits/stdc++.h>
using namespace std;
//  Preorder, Inorder , Postorder Traversal
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
if num == 1:
    preorder.push
    num++
    left push into stack
if num  == 2
    inorder
    ++
    right push into stack
if num == 3
    postorder

Time O(N)
Space O(N)
*/
void func(Node *root)
{
    stack<pair<Node *, int>> s;
    s.push({root, 1});

    vector<int> pre, in, post;

    if (root == NULL)
        return;
    while (!s.empty())
    {
        auto it = s.top();
        s.pop();

        if (it.second == 1)
        {
            pre.push_back(it.first->data);
            it.second++;
            s.push(it);

            if (it.first->left != NULL)
            {
                s.push({it.first->left, 1});
            }
        }
        else if (it.second == 2)
        {
            in.push_back(it.first->data);
            it.second++;
            s.push(it);
            if (it.first->right != NULL)
            {
                s.push({it.first->right, 1});
            }
        }
        else
        {
            post.push_back(it.first->data);
        }
    }

    // print the vectors...
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->right = new Node(4);
}