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

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];

    int pmax = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] == 1 or a[i] == 0)
        {
            if (pmax > a[i])
            {
                std::cout << "NO\n";
                return;
            }
        }

        pmax = std::max(pmax, a[i]);
    }

    std::cout << "YES\n";
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