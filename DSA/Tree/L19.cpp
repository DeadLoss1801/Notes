#include <bits/stdc++.h>
using namespace std;
//  ZigZag or Spiral Traversal of Binary Tree
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

vector<vector<int>> zigzagLevelOrder(Node *root)
{
    vector<vector<int>> result;

    if (root == NULL)
        return result;

    queue<Node *> q;
    q.push(root);

    bool flag = true;
    while (!q.empty())
    {
        int size = q.size();

        vector<int> row(size);

        for (int i = 0; i < size; i++)
        {
            Node *node = q.front();
            q.pop();

            int index = flag ? i : (size - 1 - i);

            row[index] = node->data;
            if (node->left)
            {
                q.push(node->left);
            }
            if (node->right)
            {
                q.push(node->right);
            }
        }

        flag = !flag;
        result.push_back(row);
    }
    return result;
}