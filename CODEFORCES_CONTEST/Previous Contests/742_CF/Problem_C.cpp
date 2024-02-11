#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;

int get_digit(ll n)
{
    int dig = 0;
    while(n)
        n /= 10, dig++;
    
    return dig;
}

ll pow_cust(int a)
{
    ll res = 1;
    while(a--)
        res *= 10;
    return res;
}


void solve()
{
    ll n; cin >> n;
    // int dig = get_digit(n);
    ll a = 0, b = 0;

    int turn = 0, cntA = 0, cntB = 0; 
    while(n)
    {
        if (turn == 0)
            a += (n % 10) * (pow_cust(cntA)), cntA++;
        else
            b += (n % 10) * (pow_cust(cntB)), cntB++;

        n /= 10;
        turn = (1 - turn);
        // dig--; 
    }

    ll ans = (a + 1)*(b + 1) - 2;
    // cout << a << ' ' << b << "\n";
    cout << ans << "\n";
}

int main()
{
    int t;
    cin >> t;
    while(t --)
        solve();
    return 0;
}