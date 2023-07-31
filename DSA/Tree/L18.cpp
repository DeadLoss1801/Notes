#include <bits/stdc++.h>
using namespace std;
//  check it two trees are identical or Not-->
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

bool check(Node *n1, Node *n2)
{
    if (n1 == NULL && n2 == NULL)
        return true;
    if (n1 == NULL)
        return false;
    if (n2 == NULL)
        return false;

    return n1->data == n2->data && check(n1->left, n2->left) && check(n1->right, n2->right);
}