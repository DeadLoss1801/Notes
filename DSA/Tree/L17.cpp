#include <bits/stdc++.h>
using namespace std;
//  Maximum Path sum;
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

int maxPathSum(Node *root, int &maxi)
{
    if (root == NULL)
        return 0;

    int l = max(0, maxPathSum(root->left, maxi));
    int r = max(0, maxPathSum(root->right, maxi));

    maxi = max(maxi, l + r + root->data);

    return root->data + max(l, r);
}

int func(Node *root)
{
    int maxi = INT_MIN;
    maxPathSum(root, maxi);
    return maxi;
}