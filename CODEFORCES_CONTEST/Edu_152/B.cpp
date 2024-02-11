#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, k;
    std::cin >> n >> k;

    std::multiset<std::pair<int, int>> m;
    for (int i = 0; i < n; i++)
    {
        int a;
        std::cin >> a;
        int val = a % k;
        if (val == 0)
            val += k;

        m.emplace(-val, i);
    }

    while (!m.empty())
    {
        auto [_, id] = *std::begin(m);
        m.erase(std::begin(m));
        std::cout << id + 1 << " \n"[m.empty()];
    }
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