#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr int none = 0, white = 1, black = 2;

void solve()
{
    int n, m;
    std::cin >> n >> m;

    std::vector<std::string> a(n);
    int ok = 1;
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        int cnt = 0;
        for (auto ch : a[i])
            cnt += ch != '.';

        if (cnt % 2)
            ok = 0;
    }

    for (int j = 0; j < m; j++)
    {
        int cnt = 0;
        for (int i = 0; i < n; i++)
            cnt += a[i][j] != '.';

        if (cnt % 2)
            ok = 0;
    }

    if (!ok)
    {
        std::cout << "-1\n";
        return;
    }

    std::vector b(n, std::vector(m, none));

    auto nextVertical = [&](int x, int y)
    {
        for (int col = y + 1; col < m; col++)
        {
            if (b[x][col] != none)
                continue;

            if (a[x][col] == 'U')
                return col;
        }

        assert(false);
        return -1;
    };

    auto nextHorizontal = [&](int x, int y)
    {
        for (int row = x + 1; row < n; row++)
        {
            if (b[row][y] != none)
                continue;

            if (a[row][y] == 'L')
                return row;
        }

        assert(false);
        return -1;
    };  

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if ((a[i][j] != 'U' and a[i][j] != 'D') or b[i][j] != none)
                continue;

            int x = i, y = j, z = nextVertical(i, j);
            b[x][y] = white, b[x + 1][y] = black;
            b[x][z] = black, b[x + 1][z] = white;
        }
    }

    for (int j = 0; j < m; j++)
    {
        for (int i = 0; i < n; i++)
        {
            if ((a[i][j] != 'L' and a[i][j] != 'R') or b[i][j] != none)
                continue;

            int x = i, y = j, z = nextHorizontal(i, j);
            b[x][y] = white, b[x][y + 1] = black;
            b[z][y] = black, b[z][y + 1] = white;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (b[i][j] == none)
                std::cout << '.';
            else if (b[i][j] == black)
                std::cout << 'B';
            else
                std::cout << 'W';
        }

        std::cout << "\n";
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--)
        solve();

    return 0;
}