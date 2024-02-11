#include <bits/stdc++.h>
#include <stdio.h>
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

    std::vector<std::vector<std::tuple<int, int, int>>> adj(n);

    std::vector<i64> dp1(n), dp2;
    for (int i = 1; i < n; ++i)
    {
        int p, _, __;
        std::cin >> p >> _ >> __;

        adj[--p].emplace_back(i, _, __);
        dp1[i] = _;
    }

    std::vector<int> r(n);
    dp2.push_back(0);
    std::function<void(int)> dfs = [&](int u)
    {
        r[u] = std::upper_bound(std::begin(dp2), std::end(dp2), dp1[u]) - std::begin(dp2) - 1;
        
        for (auto [v, a, b] : adj[u])
        {
            dp2.push_back(dp2.back() + b);
            dp1[v] += dp1[u];
            dfs(v);
            dp2.pop_back();
        }
    };

    dfs(0);

    for (int i = 1; i < n; i++)
        std::cout << r[i] << " \n"[i == n - 1];
}

struct G
{
    bool operator()(int a, int b)
    {
        return a < b;
    }   
};

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