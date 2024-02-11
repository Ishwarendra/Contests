#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    i64 k;
    std::cin >> n >> k;

    std::vector<std::string> a(n), b(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];
    for (int i = 0; i < n; i++)
        std::cin >> b[i];

    for (int i = 0; i < n; i++)
    {
        if (std::size(a[i]) != std::size(b[i]))
        {
            std::cout << "NO\n";
            return;
        }
    }

    std::array<std::array<int, 10>, 10> burden{};
    auto subtract = [&](int i)
    {
        for (int j = 0; j < std::size(a[i]); j++)
        {
            if (a[i][j] != b[i][j])
                burden[a[i][j] - '0'][b[i][j] - '0']--;
        }
    };

    auto add = [&](int i)
    {
        for (int j = 0; j < std::size(a[i]); j++)
        {
            if (a[i][j] != b[i][j])
                burden[a[i][j] - '0'][b[i][j] - '0']++;
        }
    };

    for (int i = 0; i < n; i++)
        add(i);

    std::array<std::array<int, 10>, 10> free_{};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < std::size(a[i]); j++)
        {
            int x = a[i][j] - '0';
            int y = b[i][j] - '0';

            if (burden[x][y] > 0 and burden[y][x] > 0)
                burden[x][y]--, burden[y][x]--, a[i][j] = b[i][j];
        } 

        subtract(i);
        add(i);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < std::size(a[i]); j++)
        {
            int x = a[i][j] - '0';
            int y = b[i][j] - '0';

            if (x == y)
                continue;

            if (free_[x][y] > 0)
            {
                free_[x][y]--;
                burden[x][y]--;
                continue;
            }

            for (int z = 0; z < 10; z++) if (z != x and z != y)
            {
                if (burden[y][z] > 0 and burden[z][x] > 0)
                {
                    free_[y][z]++;
                    free_[z][x]++;
                    a[i][j] = b[i][j];
                }
            }
        } 

        subtract(i);
    }

    int sum = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
            sum += burden[i][j] - free_[i][j];
    }

    print(a, sum)

    std::cout << (sum <= k ? "YES\n" : "NO\n");
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