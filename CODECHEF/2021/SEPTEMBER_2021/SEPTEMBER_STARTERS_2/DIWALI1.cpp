#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;

void solve()
{
    ll p, a, b, c, y, x;
    cin >> p >> a >> b >> c >> x >> y;

    if ((a*x + b) <= (a*y + c))
    {
        cout << p/(a*x + b) << endl;
        return;
    }
    else 
    {
        cout << p/(a*y + c) << endl;
        return;
    }

    
}

int main()
{
    FIO
    int t = 1;
    cin >> t;
    while(t--)
          solve();
    return 0;
}