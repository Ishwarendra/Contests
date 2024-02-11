#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

std::map<char, std::pair<int, int>> dirs {
    {'D', {1, 0}}, {'R', {0, 1}}, {'L', {0, -1}}, {'U', { -1, 0}}
};

void solve()
{
    std::array<int, 2> end{};
    std::string s;
    int x, y, n, m;
    std::cin >> n >> m >> x >> y >> end[0] >> end[1] >> s;
    x--, y--, end[0]--, end[1]--;

    std::pair<int, int> dir = dirs[s[0]];
    dir.first += dirs[s[1]].first;
    dir.second += dirs[s[1]].second;

    auto safe = [&](int i, int j)
    {
        return i >= 0 and i < n and j >= 0 and j < m;
    };

    int bounce = 0;
    std::vector vis(n, std::vector(m, 0));

    while (vis[x][y] < 100)
    {
        vis[x][y]++;
        // print(x, y)
        if (x == end[0] and y == end[1])
            break;

        auto [dx, dy] = dir;
        if (safe(x + dx, y + dy))
            x += dx, y += dy;
        else
        {
            if (x + dir.first < 0 or x + dir.first >= n)
                dir.first *= -1;
            if (y + dir.second < 0 or y + dir.second >= m)
                dir.second *= -1;

            bounce++;
            x += dir.first, y += dir.second;
        }
    }

    std::cout << (vis[end[0]][end[1]] ? bounce : -1) << "\n";
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