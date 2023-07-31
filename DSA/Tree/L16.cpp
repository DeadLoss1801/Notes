#include <bits/stdc++.h>
using namespace std;
//  Diameter of Binary tree
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
diameter = left + right
*/

int findMax(Node *root, int &maxi)
{
    if (root == NULL)
        return 0;

    int l = findMax(root->left, maxi);
    int r = findMax(root->right, maxi);
    maxi = max(maxi, l + r);

    return 1 + max(l, r);
}

int diameter(Node *root)
{
    int diameter = 0;
    findMax(root, diameter);
    return diameter;
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
}