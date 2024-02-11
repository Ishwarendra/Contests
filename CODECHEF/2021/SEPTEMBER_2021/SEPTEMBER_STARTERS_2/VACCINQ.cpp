#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;

void solve()
{
    int n, p, x, y;
    cin >> n >> p >> x >> y;
    vi a(n);
    for(int &x : a) cin >> x;

    // if (p == 1)
    // {
    //     cout << y << endl;
    //     return;
    // }

    int ans = 0;
    for(int i = 0; i < p; i++)
    {
        ans += (a[i] == 1 ? y : x);
    }
    cout << ans << "\n";
    
}

int main()
{
    int t = 1;
    cin >> t;
    while(t--)
          solve();
    return 0;
}