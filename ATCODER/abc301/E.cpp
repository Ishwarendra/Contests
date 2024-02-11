#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr int inf = 1e9;

std::vector<std::array<int, 2>> dirs {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

std::vector<std::vector<int>> bfs(auto &a, std::array<int, 2> st)
{
    int n = std::size(a);
    int m = std::size(a[0]);

    std::queue<std::pair<int, int>> q;
    std::vector d(n, std::vector(m, inf));
    q.emplace(st[0], st[1]);
    d[st[0]][st[1]] = 0;

    auto safe = [&](int i, int j)
    {
        bool bounded = 0 <= i and i < n and 0 <= j and j < m;
        if (!bounded)
            return false;
        return bounded and a[i][j] != '#' and d[i][j] == inf;
    };

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        for (auto [dx, dy] : dirs)
        {
            if (!safe(x + dx, y + dy))
                continue;
            d[x + dx][y + dy] = d[x][y] + 1;
            q.emplace(x + dx, y + dy);
        }
    }

    return d;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m, t;
    std::cin >> n >> m >> t;

    std::vector<std::string> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    std::vector<std::array<int, 2>> srcs;
    std::array<int, 2> st{}, en{};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == 'o')
                srcs.push_back({i, j});
            if (a[i][j] == 'S')
                st = std::array {i, j};
            if (a[i][j] == 'G')
                en = std::array {i, j};
        }
    }

    auto ds = bfs(a, st);

    if (ds[en[0]][en[1]] > t)
    {
        std::cout << -1;
        return 0;
    }

    int sz = std::size(srcs);
    std::vector d(sz, std::vector(sz, inf));
    int pos = 0;
    for (auto src : srcs)
    {
        auto d1 = bfs(a, src);
        for (int i = 0; i < sz; i++)
            d[pos][i] = d1[srcs[i][0]][srcs[i][1]];
        pos++;
    }

    const int M = 1 << sz;
    std::vector dp(sz, std::vector(M, inf));

    for (int i = 0; i < sz; i++)
        dp[i][1 << i] = ds[srcs[i][0]][srcs[i][1]];

    auto getBit = [&](int x, int pos) { return x >> pos & 1; };

    for (int mask = 0; mask < M; mask++)
    {
        for (int v = 0; v < sz; v++)
        {
            for (int u = 0; u < sz; u++)
            {
                if (!getBit(mask, v) || !getBit(mask, u) || u == v || d[u][v] == inf)
                    continue;

                dp[v][mask] = std::min(dp[v][mask], dp[u][mask ^ (1 << v)] + d[u][v]);
            }
        }
    }

    int ans = 0;
    auto de = bfs(a, en);
    for (int mask = 0; mask < M; mask++)
    {
        for (int i = 0; i < sz; i++)
        {
            if (!getBit(mask, i))
                continue;

            if (dp[i][mask] + de[srcs[i][0]][srcs[i][1]] <= t)
                ans = std::max(ans, __builtin_popcount(mask));
        }
    }

    std::cout << ans;

    return 0;
}