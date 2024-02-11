#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h>
#else
#define trace(...) 1;
#define print(...) 1;
#endif

void solve()
{
    int n;
    std::cin >> n;

    std::vector<std::set<int>> adj(n);
    std::vector<int> cnt(n);
    std::string ans = "YES\n";

    for (int i = 0; i < n; ++i)
    {
        int a, b;
        std::cin >> a >> b;
        a--, b--;

        cnt[a]++, cnt[b]++;
        adj[a].emplace(b);
        adj[b].emplace(a);

        if (cnt[a] > 2 or cnt[b] > 2 or a == b)
            ans = "NO\n";
    }

    std::fill(std::begin(cnt), std::end(cnt), 0);
    std::function<bool(int, int)> dfs;

    dfs = [&](int u, int c)
    {
        if (!cnt[u])
            cnt[u] = c;
        else 
            return cnt[u] == c;

        bool can = true;

        for (int v : adj[u])
            can &= dfs(v, 3 - c);

        return can;
    };

    for (int i = 0; i < n; i++)
    {
        if (!cnt[i])
        {
            bool possible = dfs(i, 1);
            if (!possible)
                ans = "NO\n";
        }
    }

    std::cout << ans;
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