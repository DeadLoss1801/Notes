#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define vi vector<int>
#define pb push_back

int32_t main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n, p, k;
        cin >> n >> p >> k;
        int m = p % k;
        int d = n / k;
        int mx = n % k;

        int total = 0;
        if (mx >= m && m != 0)
        {
            total += (m - 1) * (d + 1);
            total += (p / k);
        }
        else if (m == 0)
        {
            total = p / k;
        }
        else
        {
            total += (mx) * (d + 1);
            total += (m - mx) * d;
            total += (p / k);
        }
        cout << total + 1 << endl;
    }
}

// 0 5 10 1 6 2 7  3