#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;

void solve()
{
    int n, a, b;
    cin >> n >> a >> b;

    int even = 0, odd = 0;

    for (int i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            (i & 1) ? odd++ : even++;
            n /= i;
        }
    }

    if (n > 1)
        (n % 2 == 1) ? odd++ : even++;
    int ans = 0;

    if (a >= 0 and b >= 0)
        ans = even * a + odd * b;
    if (a >= 0 and b < 0)
        ans = (even > 0 ? even * a : b);    
    if (a < 0 and b >= 0)
        ans = odd * b + (even ? a : 0);
    if (a < 0 and b < 0)
        ans = (even > 0) ? a : b;


    cout << ans << "\n";
}

int main()
{
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}