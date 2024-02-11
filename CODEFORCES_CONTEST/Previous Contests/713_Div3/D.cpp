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
    int n;
    std::cin >> n;

    std::vector<int> b(n + 2);
    for (int i = 0; i < n + 2; ++i)  
        std::cin >> b[i];

    std::sort(std::begin(b), std::end(b));
    i64 sum = std::accumulate(std::begin(b), std::begin(b) + n, 0LL);

    if (sum == b[n] or sum == b[n + 1])
    {
        for (int i = 0; i < n; ++i)
            std::cout << b[i] << " \n"[i + 1 == n];

        return;
    }

    sum += b[n];
    for (int i = 0; i < n; i++)
    {
        sum -= b[i];

        if (sum == b.back())
        {
            for (int j = 0; j < n + 1; j++)
            {
                if (j == i)
                    continue;
                std::cout << b[j] << " ";
            }

            std::cout << std::endl;
            return;
        }

        sum += b[i];
    }

    std::cout << "-1\n";
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