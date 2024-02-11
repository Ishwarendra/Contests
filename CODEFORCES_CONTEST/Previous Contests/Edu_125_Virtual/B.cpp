#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    const int n = 10;
    std::vector<std::string> a(n);

    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    auto safe = [&](int i, int j)
    {
        return i >= 0 and j >= 0 and i < n and j < n;
    };

    auto right = [&](int i, int j)
    {
        if (!safe(i, j + 4))
            return false;

        int count = 0, tot = 5;
        while (tot--)
            count += a[i][j++] == 'X';

        return count == 5;
    };

    auto down = [&](int i, int j)
    {
        if (!safe(i + 4, j))
            return false;

        int count = 0, tot = 5;
        while (tot--)
            count += a[i++][j] == 'X';

        return count == 5;
    };

    auto dia = [&](int i, int j)
    {
        int x = i, y = j;
        int tot = 5, count = 0;

        if (safe(i + 4, j + 4))
        {
            while (tot--)
                count += a[x++][y++] == 'X';

            if (count == 5)
                return true;
        }

        x = i, y = j, tot = 5, count = 0;
        if (safe(i + 4, j - 4))
        {
            while (tot--)
                count += a[x++][y--] == 'X';

            if (count == 5)
                return true;
        }

        return false;
    };

    auto check = [&]()
    {
        int can = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                can |= right(i, j) | down(i, j) | dia(i, j);
        }

        return can;
    };

    int can = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == '.')
            {
                a[i][j] = 'X';
                can |= check();
                a[i][j] = '.';
            }
        }
    }

    std::cout << (can ? "YES\n" : "NO\n");
    
    return 0;
}