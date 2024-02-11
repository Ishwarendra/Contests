#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;

int win(ll n)
{
    if (n == 0)
        return 0;
    if (n % 2 != 0)
        return 1 - win(n - 1);
    if (n % 4 != 0)
        return 1 - !win(n >> 1);
    return 1;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        cout << ((win(n)) ? "Alice\n" : "Bob\n");
    }
    return 0;
}