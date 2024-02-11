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
    std::cin >> n;

    if (n & 1)  
    {
        for (int i = 0; i < n; i++)
            std::cout << 1 << " \n"[i == n - 1];
    }
    else
    {
        if (n == 2)
            std::cout << "1 3\n";
        else if (n == 4)
            std::cout << "13 2 8 1\n";
        else
        {
            for (int i = 0; i < n - 4; i++)
                std::cout << "6 ";
            std::cout << "13 2 8 1\n";
        }
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