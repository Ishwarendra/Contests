#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr int inf = 1e9;
std::vector<std::pair<int, int>> dir {{0, 1}, {1, 0}, { -1, 0}, {0, -1}};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::map<char, std::pair<int, int>> dirs;
    dirs['>'] = {0, 1};
    dirs['<'] = {0, -1};
    dirs['^'] = { -1, 0};
    dirs['v'] = {1, 0};

    int n, m;
    std::cin >> n >> m;
    std::vector<std::string> a(n);
    std::vector block(n, std::vector(m, 0)), done(n, std::vector(m, 0));
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    dirs['#'] = {n, m};


    auto safe = [&](int i, int j)
    {
        return i >= 0 and i < n and j >= 0 and j < m;
    };

    std::array<int, 2> st{}, en{};

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == 'S')
                st = {i, j};
            if (a[i][j] == 'G')
                en = {i, j};

            if (!dirs.count(a[i][j]) or done[i][j])
                continue;

            block[i][j] = 1;
            done[i][j] = 1;

            auto [dx, dy] = dirs[a[i][j]];
            char pair = '!';
            if (a[i][j] == '>' || a[i][j] == '<')
                pair = '<' ^ '>' ^ a[i][j];
            if (a[i][j] == '^' || a[i][j] == 'v')
                pair = 'v' ^ '^' ^ a[i][j];

            int x = i + dx, y = j + dy;
            while (safe(x, y))
            {
                block[x][y] = 1;
                if (dirs.count(a[x][y]))
                {
                    if (pair == a[x][y])
                        done[x][y] = 1;
                    break;
                }
                x += dx, y += dy;
            }
        }
    }

    auto bfs = [&]()
    {
        std::queue<std::array<int, 2>> q;
        done.assign(n, std::vector(n, inf));
        done[st[0]][st[1]] = 0;
        q.emplace(st);

        while (!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();

            for (auto [dx, dy] : dir)
            {
                if (safe(x + dx, y + dy) and !block[x + dx][y + dy] and done[x + dx][y + dy] == inf)
                {
                    done[x + dx][y + dy] = done[x][y] + 1;
                    q.push({x + dx, y + dy});
                }
            }
        }

        return done[en[0]][en[1]] == inf ? -1 : done[en[0]][en[1]];
    };

    std::cout << bfs();

    return 0;
}