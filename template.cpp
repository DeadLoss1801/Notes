#include <bits/stdc++.h>
using namespace std;
#define fio                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define int long long int
#define vi vector<int>
#define w(x)  \
    int x;    \
    cin >> x; \
    while (x--)
#define pb push_back

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fio
    w(t)
    {
        int n;
        cin >> n;
        cout << (n - 1) * (n - 2) + 1 << "\n";
    }
}