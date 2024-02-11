#include<bits/stdc++.h>

#define LOCAL

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h>
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> p(n), where(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> p[i];
        p[i]--;

        where[p[i]] = i;
    }

    int m;
    std::cin >> m;
    std::map<std::pair<int, int>, int> id;
    std::vector<std::vector<int>> adj(n);
    std::vector<std::pair<int, int>> edg;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        std::cin >> a >> b;
        a--, b--;

        edg.emplace_back(std::min(a, b), std::max(a, b));
        adj[a].push_back(b);
        adj[b].push_back(a);

        id[std::pair<int, int>(a, b)] = i + 1;
        id[std::pair<int, int>(b, a)] = i + 1;
    }

    std::vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        if (i == p[i])
            continue;

        int start = where[i];

        std::vector<int> vis(n), path, finalPath;
        std::function<void(int, int)> dfs;
        dfs = [&](int src, int dest)
        {
            vis[src] = 1;
            path.push_back(src);

            if (src == dest)
            {
                for (auto i : path)
                    finalPath.push_back(i);

                return;
            }

            for (int nb : adj[src])
            {
                if (!vis[nb])
                    dfs(nb, dest);
            }

            path.pop_back();
        };

        dfs(start, i);
        if (finalPath.size() and finalPath.back() == i)
        {
            print(start, i, finalPath);
            for (int i = 1; i < finalPath.size(); i++)
            {
                int f = finalPath[i - 1], s = finalPath[i];
                std::swap(p[f], p[s]);
                ans.push_back(id[{f, s}]);
            }
        }
        else
        {
            std::cout << "-1\n";
            return 0;
        }
    }

    std::cout << ans.size() << "\n";
    for (int i : ans)
        std::cout << i << " ";

    assert(is_sorted(p.begin(), p.end()));

    return 0;
}