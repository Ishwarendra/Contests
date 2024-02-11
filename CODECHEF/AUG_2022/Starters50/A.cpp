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
    int n, x;
    std::cin >> n >> x;

    if (x < n)  
        std::cout << "-1\n";
    else
    {
        std::cout << x - (n - 1) << " ";
        for (int i = 1; i <= n; i++)
        {
            if (i == x - n + 1)
                continue;

            std::cout << i << " ";
        }

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