#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    std::array<std::string, 2> a;
    std::cin >> n >> a[0] >> a[1];

    std::string ans;
    ans += a[0][0];
    int down = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (down == 1)
            ans += a[1][i];
        else if (a[0][i + 1] == '1' and a[1][i] == '0')
            ans += a[1][i], down = 1;
        else
            ans += a[0][i + 1];
    }

    ans += a[1][n - 1];

    std::cout << ans << "\n";
    int pref = 0, suff = 0;
    while (pref < n and a[0][pref] == ans[pref])
        pref++;
    while (suff < n and a[1][n - suff - 1] == ans[n - suff])
        suff++;

    int ways = 0;
    for (int i = 0; i < n; i++)
    {
        if (pref >= i + 1 and suff >= n - i)
            ways++;
    }

    std::cout << ways << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}