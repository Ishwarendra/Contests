#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<std::string> a(n);
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];

    std::array<int, 2> min{n, n}, max{};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == '1')
            {
                min = std::min(min, std::array {i, j});
                max = std::max(max, std::array {i, j});
            }
        }
    }

    auto isSquare = [&]()
    {
        for (int i = min[0]; i <= max[0]; i++)
        {
            for (int j = min[1]; j <= max[1]; j++)
            {
                if (a[i][j] != '1')
                    return false;
            }
        }

        return true;
    };

    if (isSquare())
        std::cout << "SQUARE\n";
    else
        std::cout << "TRIANGLE\n";
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