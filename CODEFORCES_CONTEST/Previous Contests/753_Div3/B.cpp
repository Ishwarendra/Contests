#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;
using ull = unsigned long long;

void solve()
{
    ll x, n;
    cin >> x >> n;

    if (n == 0)
        cout << x << "\n";
    else if (n == 1)
        cout << ((x & 1) ? x + 1 : x - 1) << "\n";
    else if (n == 2)
    {
        if (x % 2 == 0)
        {
            cout << x + 1 << "\n";
        }
        else 
        {
            cout << x - 1 << "\n";
        }
    }
    else 
    {   
        ll type = (n + 1) % 4;
        ll start2, start4;
        // 0 -> x; 1 -> (some number +/- 4); 2 -> x + 1; 3 -> (some number +/- 4)
        if (x % 2 == 0)
        {
            start2 = x - 1, start4 = x + 4; 
            ll term = (n / 4) + 1;
            ll ans;
            if (type == 1)
                ans = x;
            else if (type == 2)
                ans = start2 - 4 * (term - 1);
            else if (type == 3)
                ans = x + 1;
            else
                ans = start4 + 4 * (term - 1);

                cout << ans << "\n";
        }
        else
        {
            start2 = x + 1; start4 = x - 4;
            ll term = (n / 4) + 1;

            ll ans;
            if (type == 1)
                ans = x;
            else if  (type == 2)
                ans = start2 + 4*(term - 1);
            else if (type == 3)
                ans = x - 1;
            else
                ans = start4 - 4*(term - 1);

                cout << ans << "\n";
        }
    }

}

int main()
{
    int t = 1;
    cin >> t;
    while(t--)
          solve();
    return 0;
}