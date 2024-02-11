#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using namespace std;

using i64 = long long;

constexpr int inf = 1e9;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;

    std::vector<std::string> a(n);
    std::vector<int> adj[n], radj[n];

    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        for (int j = 0; j < m and i + j + 1 < n; j++)
        {
            if (a[i][j] == '1')
            {
                radj[i + j + 1].emplace_back(i);
                adj[i].emplace_back(i + j + 1);
            }
        }
    }

    auto bfs = [&](int src, auto adj[])
    {
        std::vector<int> dist(n, inf);
        std::queue<int> q;
        q.emplace(src);
        dist[src] = 0;

        while (!q.empty())
        {
            auto u = q.front();
            q.pop();

            for (auto v : adj[u])
            {
                if (dist[v] > dist[u] + 1)
                    dist[v] = dist[u] + 1, q.emplace(v);
            }
        }

        return dist;
    };

    auto from_src = bfs(0, adj);
    auto from_sink = bfs(n - 1, radj);

    for (int k = 1; k < n - 1; k++)
    {
        int ans = inf;
        for (int u = k - 1; u > k - m and u >= 0; u--)
        {
            for (int v : adj[u]) if (v != k and v > k)
                ans = std::min(ans, from_src[u] + from_sink[v] + 1);
        }

        if (ans == inf)
            std::cout << "-1 ";
        else
            std::cout << ans << " ";
    }

    return 0;
}