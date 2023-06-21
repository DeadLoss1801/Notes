#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e5 + 2;
int arr[N],
    pair<int, int> tree[4 * N];

void build(int node, int st, int en)
{
    if (st == en)
    {
        tree[node] = {arr[st], 1};
        return;
    }
    int mid = st + (en - st) / 2;
    build(2 * node, st, mid);
    build(2 * node + 1, mid + 1, en);

    if (tree[2 * node].first < tree[2 * node + 1].first)
    {
        tree[node].first = tree[2 * node + 1].first;
        tree[node].second = tree[2 * node + 1].second;
    }
    else if (tree[2 * node].first > tree[2 * node + 1].first)
    {
        tree[node].first = tree[2 * node].first;
        tree[node].second = tree[2 * node].second;
    }
    else
    {
        tree[node].first = tree[2 * node].first;
        tree[node].second = tree[2 * node].second + tree[2 * node + 1].second;
    }
}

pair<int, int> query(int node, int st, int en, int l, int r)
{
    if (st > r || en < l)
        return {INT_MAX, 0};

    if (l <= st && en <= r)
    {
        return tree[node];
    }
    int mid = st + (en - st) / 2;
    pair<int, int> q1 = query(2 * node, st, mid, l, r);
    pair<int, int> q2 = query(2 * node + 1, mid + 1, en, l, r);
    pair<int, int> q;
    if (q1.first < q2.first)
    {
        q = q1;
    }
    else if (q2.first < q1.first)
    {
        q = q2;
    }
    else
    {
        q.first = q1.first;
        q.second = q1.second + q2.second;
    }
    return q;
}

void update(int node, int st, int en, int idx, int val)
{
    if (st == en)
    {
        arr[st] = val;
        tree[node] = {val, 1};
        return;
    }
    int mid = st + (en - st) / 2;
    if (idx <= mid)
    {
        update(2 * node, st, mid, idx, val);
    }
    else
    {
        update(2 * node + 1, mid + 1, en, idx, val);
    }
    if (tree[2 * node].first < tree[2 * node + 1].first)
    {
        tree[node].first = tree[2 * node + 1].first;
        tree[node].second = tree[2 * node + 1].second;
    }
    else if (tree[2 * node].first > tree[2 * node + 1].first)
    {
        tree[node].first = tree[2 * node].first;
        tree[node].second = tree[2 * node].second;
    }
    else
    {
        tree[node].first = tree[2 * node].first;
        tree[node].second = tree[2 * node].second + tree[2 * node + 1].second;
    }
}
