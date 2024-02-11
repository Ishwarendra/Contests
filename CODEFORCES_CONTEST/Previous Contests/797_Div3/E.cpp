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
    i64 ans = 0;
    std::multiset<std::pair<int, int>> m;

    for (int i = 0; i < n; ++i)
    {
        std::cin >> a[i];
        ans += a[i] / k;
        m.insert({a[i] % k, i});
    }

    while (!m.empty())
    {
        auto [mod, id] = *m.begin();
        m.erase(m.begin());

        // k = 0 case actually solved by not taking mod since no ele with rem >= k can exist
        auto it = m.lower_bound({(k - mod), 0}); 

        if (it != m.end())
        {
            m.erase(it);
            ans++;
        }
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