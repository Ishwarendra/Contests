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

    int sum = 0;
    for (int i = 1; i <= n; i++)
        sum += i * (2 * i - 1);
    
    std::cout << sum << " " << 2 * n << "\n";
    for (int i = n; i > 0; i--)
    {
        for (int j = 1; j <= 2; j++)
        {
            std::cout << j << " " << i << " ";
            for (int k = 1; k <= n; k++)
                std::cout << k << " \n"[k == n];
        }
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