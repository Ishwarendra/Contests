#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    std::string a, b;
    std::cin >> a >> b;

    int n = std::size(a), m = std::size(b);
    if (a[0] == b[0])  
        std::cout << "YES\n" << a[0] << "*\n";
    else if (a.back() == b.back())
        std::cout << "YES\n*" << a.back() << "\n";
    else
    {
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < m - 1; j++)
            {
                if (a.substr(i, 2) == b.substr(j, 2))
                {
                    std::cout << "YES\n*" << a.substr(i, 2) << "*\n";
                    return;
                }
            }
        }

        std::cout << "NO\n";
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