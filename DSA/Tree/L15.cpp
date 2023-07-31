#include <bits/stdc++.h>
using namespace std;
//  check for Balanced Binary tree
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
    abs(left's height - right's height ) <= 1;
*/
int maxDepth(Node *root)
{
    if (root == NULL)
        return 0;

    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

bool check(Node *root)
{
    if (root == NULL)
        return true;

    // finding left  & right tree height;
    int l = maxDepth(root->left); // O(N)
    int r = maxDepth(root->right);

    return abs(l - r) <= 1 && check(root->left) && check(root->right); // O(N)
}

// so Time O(N^2)

// --- O(N) ---  solution

int check2(Node *root)
{
    if (root == NULL)
        return 0;

    int l = check2(root->left);
    int r = check2(root->right);

    if (l == -1 || r == -1)
        return -1;
    if (abs(l - r) > 1)
        return -1;

    return 1 + max(l, r);
}
