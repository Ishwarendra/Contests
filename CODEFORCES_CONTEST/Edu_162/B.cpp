#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, k;
    std::cin >> n >> k;

    std::map<int, i64> a;
    std::vector<int> h(n);

    i64 max = 0;
    for (int i = 0; i < n; i++)
        std::cin >> h[i];
    for (int i = 0; i < n; i++)
    {
        int p;
        std::cin >> p;
        a[std::abs(p)] += h[i];
        max += h[i];
    }

    i64 bullets = 0, sub = 0;
    int stop = 0;

    for (auto &[pos, health] : a)
    {
        if (bullets >= max)
            stop = 1;

        if (!stop)
            bullets += 1LL * (pos - sub) * k;

        if (health > bullets)
        {
            std::cout << "NO\n";
            return;
        }

        bullets -= health;
        sub = pos;
    }

    std::cout << "YES\n";
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