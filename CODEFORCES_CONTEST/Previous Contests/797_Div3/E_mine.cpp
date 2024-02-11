#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    std::multiset<std::pair<int, int>> m;

    for (int i = 0; i < n; ++i)  
    {
        std::cin >> a[i];
        m.insert({a[i] % k, a[i]});
    }

    i64 ans = 0;
    while (!m.empty())
    {
        auto [mod, id] = *m.begin();
        m.erase(m.begin());

        auto it = m.lower_bound({(k - mod), 0});
        if (it == m.end())
            it = m.lower_bound({0, 0});
        if (it == m.end())
            it--;

        auto [_, id2] = *it;
        ans += (1LL * (id + id2)) / k;
        m.erase(it);
    }

    std::cout << ans << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    
    while(t--)
        solve();
    
    return 0;
}