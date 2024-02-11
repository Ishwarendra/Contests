#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif

void solve()
{
    int n, m;
    std::cin >> n >> m;

    std::vector<std::string> a(n);
    std::set<std::pair<int, int>> s;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> a[i];

        for (int j = 0; j < m; ++j)
            if (a[i][j] == 'B')
                s.emplace(i, j);
    }

    std::vector<std::pair<int, int>> pts {{0, 0}, {0, m - 1}, {n - 1, 0}, {m - 1, n - 1}};
    std::vector<std::vector<int>> dist;

    for (auto [x, y] : pts)
    {
        int max = 0;

        for (auto [i, j] : s)
            max = std::max(max, abs(i - x) + abs(y - j));

        dist.push_back({max, x, y});
    }

    std::sort(dist.begin(), dist.end());
    
    std::cout << dist[0][0] << "\n";
    std::cout << dist[0][1] + 1 << " " << dist[0][2] + 1 << "\n";
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