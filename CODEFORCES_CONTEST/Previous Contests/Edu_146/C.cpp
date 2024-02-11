#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, s1, s2;
    std::cin >> n >> s1 >> s2;

    std::vector<std::array<int, 2>> a(n);
    for (int i = 0; i < n; i++)  
    {
        std::cin >> a[i][0];
        a[i][1] = i + 1;
    }

    std::sort(std::rbegin(a), std::rend(a));
    std::vector<int> p, q;

    std::array<i64, 2> sum{};
    for (int i = 0; i < n; i++)
    {
        sum[0] = (std::size(p) + 1LL) * a[i][0] * s1;
        sum[1] = (std::size(q) + 1LL) * a[i][0] * s2;
        if (sum[0] <= sum[1])
            p.emplace_back(a[i][1]);
        else
            q.emplace_back(a[i][1]);
    }

    std::cout << std::size(p) << " ";
    for (auto x : p)
        std::cout << x << " ";
    std::cout << "\n" << std::size(q) << " ";
    for (auto x : q)
        std::cout << x << " ";
    std::cout << "\n";
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