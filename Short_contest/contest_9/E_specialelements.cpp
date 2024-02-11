#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<i64> a(n);
    for (int i = 0; i < n; ++i)  
        std::cin >> a[i];

    auto pref = a;
    for (int i = 1; i < n; i++)
        pref[i] += pref[i - 1];

    std::vector<int> vis(n + 1);

    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            i64 cur = pref[j] - (i - 1 >= 0 ? pref[i - 1] : 0LL);
            if (cur <= n)
                vis[cur] = 1;
        }
    }

    int ans  = 0;
    for (int i : a)
        ans += vis[i];

    std::cout << ans << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}