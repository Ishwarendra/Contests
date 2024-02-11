#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;



int main()
{
    int t; cin >> t;
    while(t--)
    {
        ll x, y;
        cin >> x >> y;
        if (x > y) swap(x, y);

        if (x % 2 == 0 and y % 2 == 0)
            cout << 0 << '\n';
        else if (x % 2 == 0 or y % 2 == 0)
        {
            if (__gcd(x, y) > 1)
                cout << 0 << '\n';
            else
                cout << 1 << '\n';
        }
        else if (x % 2 != 0 and y % 2 != 0)
        {
            if (__gcd(x, y) > 1)
                cout << 0 << '\n';
            else if (__gcd(x + 1, y) > 1 or __gcd(x, y+1) > 1)
                cout << 1 << '\n';
            else
                cout << 2 << '\n';
        }
    }
        return 0;
}