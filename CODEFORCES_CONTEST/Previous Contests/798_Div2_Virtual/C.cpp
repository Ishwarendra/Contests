#include <bits/stdc++.h>


#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif

void solve()
{
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> adj(n);

    for (int i = 0; i < n - 1; ++i)  
    {
        int u, v;
        std::cin >> u >> v;

        adj[--u].push_back(--v);
        adj[v].push_back(u);
    }

    std::vector<int> vis(n);
    std::vector<std::vector<int>> dp(n, std::vector<int>(2));
    std::function<std::vector<int>(int)> dfs;

    dfs = [&](int cur) -> std::vector<int>
    {
        if (cur == -1)
            return {0, 0};

        vis[cur] = 1;
        int left = -1, right = -1;

        for (int nb : adj[cur])
        {
            if (!vis[nb])
                (left == -1 ? left = nb : right = nb);
        }

        if (left == -1 and right == -1)
            return {0, 1}; 

        // if (left != -1)
            // dp[left] = dfs(left);
        // if (right != -1)
            // dp[right] = dfs(right);

        std::vector<int> dpl = dfs(left);
        std::vector<int> dpr = dfs(right);

        return {-1 + std::max(dpl[0] + dpr[1], dpl[1] + dpr[0]),
            dpl[1] + dpr[1] + 1};
    };
    
    auto a = dfs(0);
    std::cout << a[0] << "\n";    
    // std::cout << "hell\n";   
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