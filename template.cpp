#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

#define int long long int
#define vi vector<int>
#define pb push_back

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    double a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << fixed << setprecision(12) << (a / b) / (1 - (1 - a / b) * (1 - c / d));
}
