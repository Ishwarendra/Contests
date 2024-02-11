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

    std::vector<int> adj[n];
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        std::cin >> u >> v;

        adj[--u].push_back(--v);
        adj[v].push_back(u);
    }

    std::vector<int> dep(n, -1), in(n), out(n), par(n);
    int tme = 1;
    std::function<void(int, int)> dfs = [&](int u, int p)
    {
        par[u] = p;
        dep[u] = dep[p] + 1;
        in[u] = tme++;

        for (int v : adj[u])
        {
            if (v != p)
                dfs(v, u);
        }

        out[u] = tme;
    };

    auto isAncestor = [&](int u, int v)
    {
        return in[u] <= in[v] and out[u] >= out[v];  
    };  

    dfs(0, 0);
    const int M = std::__lg(n) + 2;
    const int N = n;

    std::vector<std::vector<int>> dp(N, std::vector<int>(M));

    for (int j = 0; j < M; ++j)
    {
        for (int i = 0; i < n; ++i)
        {
            if (j == 0)
                dp[i][j] = par[i];
            else
                dp[i][j] = dp[dp[i][j - 1]][j - 1];
        }
    }

    auto LCA = [&](int u, int v)
    {
        if (dep[u] > dep[v])
            std::swap(u, v);

        if (isAncestor(u, v))
            return u;

        int up = dep[v] - dep[u];
        
        for (int pos = 20; pos >= 0; --pos)
        {
            if ((up >> pos) & 1)
                v = dp[v][pos];
        }

        if (v == u)
            return u;

        for (int i = M - 1; i >= 0; --i)
        {
            if (dp[u][i] == dp[v][i])
                continue;

            u = dp[u][i];
            v = dp[v][i];
        }

        u = dp[u][0];
        v = dp[v][0];

        assert(u == v);
        return u;
    };

    int q;
    std::cin >> q;

    while (q--)
    {
        int k;
        std::cin >> k;

        std::vector<int> p(k);
        for (int i = 0; i < k; ++i)
        {
            std::cin >> p[i];
            p[i]--;
        }

        if (std::size(p) <= 2)
        {
            std::cout << "YES\n";
            continue;
        }

        std::sort(std::begin(p), std::end(p), [&](int a, int b)
        {
            return dep[a] > dep[b];
        });

        std::set<int> done;
        int least_depth = dep[p.back()];

        for (int i = 0; i < k; ++i)
        {
            if (isAncestor(p[i], p[0]))
                done.emplace(p[i]);
        }

        // first unmarked and p[0] LCA
        // next unmarked must be ancestor of this first unmarked
        int funmarked = -1;
        bool can = true;

        for (int i = 0; i < k; i++)
        {
            if (done.count(p[i]))
                continue;

            done.emplace(p[i]);
            if (funmarked == -1)
            {
                funmarked = p[i];
                int cur_lca = LCA(funmarked, p[0]);

                if (dep[cur_lca] > least_depth)
                     can = false;
                else
                    least_depth = dep[cur_lca];
            }
            else
            {
                if (!isAncestor(p[i], funmarked) or dep[LCA(p[i], funmarked)] < least_depth)
                    can = false;
            }
        }    

        std::cout << (can ? "YES\n" : "NO\n");
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;

    while (t--)
        solve();

    return 0;
}