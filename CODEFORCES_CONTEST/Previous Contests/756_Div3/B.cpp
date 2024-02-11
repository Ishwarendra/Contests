#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;
using ull = unsigned long long;

void solve()
{
    ll a, b;
    cin >> a >> b;
    cout << min({a, b, (a + b)/4}) << "\n";   
}

int main()
{
    int t = 1;
    cin >> t;
    while(t--)
          solve();
    return 0;
}