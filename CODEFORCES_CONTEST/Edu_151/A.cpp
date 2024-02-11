#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, k, x;
    std::cin >> n >> k >> x;

    if (k == 1)
        std::cout << "NO\n";
    else if (k == 2)
    {
        if (x == 1)
        {
            if (n % 2)
                std::cout << "NO\n";
            else
            {
                std::cout << "YES\n";
                std::cout << n / 2 << "\n";
                for (int i = 0; i < n; i += 2)
                    std::cout << 2 << " ";
                std::cout << "\n";
            }
        }
        else
        {
            std::cout << "YES\n";
            std::cout << n << "\n";
            for (int i = 0; i < n; i++)
                std::cout << 1 << " ";
            std::cout << "\n";
        }
    }
    else
    {
        if (x != 1)
        {
            std::cout << "YES\n";
            std::cout << n << "\n";
            for (int i = 0; i < n; i++)
                std::cout << 1 << " ";
            std::cout << "\n";
        }
        else 
        {
            if (n == 1)
                std::cout << "NO\n";
            else
            {
                std::cout << "YES\n";
                if (n == 2)
                    std::cout << "1\n2\n";
                else if (n == 3)
                    std::cout << "1\n3\n";
                else if (n % 2 == 0)
                {
                    std::cout << n / 2 << "\n";
                    for (int i = 0; i < n; i += 2)
                        std::cout << 2 << " ";
                    std::cout << "\n";
                }
                else
                {
                    std::cout << (n - 3) / 2 + 1 << "\n";
                    n -= 3;
                    std::cout << 3 << " ";
                    for (int i = 0; i < n; i += 2)
                        std::cout << 2 << " ";
                    std::cout << "\n";
                }
            }
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