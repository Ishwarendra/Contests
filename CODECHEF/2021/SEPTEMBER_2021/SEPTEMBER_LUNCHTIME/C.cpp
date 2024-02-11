#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;

bool is_power_of_2(ll n) // Not inlcuding 2 as it is a loosing state
{
    if (n == 2)
        return false;

    return (n & (n - 1)) == 0;
}

void solve()
{
    ll n;
    cin >> n;

    bool alice_turn = true;
    while (n > 0)
    {
        if (n == 1)
        {
            cout << (alice_turn ? "Alice\n" : "Bob\n");
            return;
        }
        else if (n & 1)
            n--;
        else if (n % 4 == 0)
        {
            cout << (alice_turn ? "Alice\n" : "Bob\n");
            return;
        }
        else
            n /= 2;

        alice_turn = !alice_turn;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}