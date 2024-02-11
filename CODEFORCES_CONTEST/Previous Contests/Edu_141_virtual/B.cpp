#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

std::vector<std::pair<int, int>> dirs {{1, 0}, {0, 1}};

void solve()
{
    int n;
    std::cin >> n;

    std::vector a(n, std::vector<int>(n, -1));
    
    // h _ _ _
    // _     h
    // h _ _ _ 
    // _     h

    int big = n * n, small = 1;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            for (int j = 0; j < n; j++)
            {
                if ((i + j) % 2 == 0)
                    a[i][j] = big--;
                else
                    a[i][j] = small++;
            }
        }
        else
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if ((i + j) % 2 == 0)
                    a[i][j] = big--;
                else
                    a[i][j] = small++;
            }
        }
    }

    for (auto x : a)
    {
        for (auto i : x)
            std::cout << i << " ";
        std::cout << "\n";
    }
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