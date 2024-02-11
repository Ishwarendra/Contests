#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int a, b, c;
    std::cin >> a >> b >> c;

    std::vector<int> sorted {a, b, c};
    std::sort(std::begin(sorted), std::end(sorted));

    for (int i = 1; i <= 10; ++i)
    {
        for (int j = 1; j <= 10; ++j)
        {
            for (int k = 1; k <= 10; ++k)
            {
                std::vector<int> temp = {std::min(i, j), std::min(j, k), std::min(i, k)};

                std::sort(std::begin(temp), std::end(temp));

                if (temp == sorted)
                {
                    std::cout << "YES\n";
                    return;
                }
            }
        }
    }

    std::cout << "NO\n";
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