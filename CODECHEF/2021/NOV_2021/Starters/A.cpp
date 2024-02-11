#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;
using ull = unsigned long long;

void solve()
{
    int a, b, p, q;
    cin >> a >> b >> p >> q;

    bool initial = (a + b) % 2, final = (p + q) % 2;

    if (a == p and b == q)
        cout << "0\n";
    else if (initial == final)
        cout << "2\n";
    else
        cout << "1\n";   
}

int main()
{
    int t = 1;
    cin >> t;
    while(t--)
          solve();
    return 0;
}