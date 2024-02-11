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

    int n = std::size(a);
    for (int i = 0; i < n; i++)  
    {
        int ok = 0;
        if (a[i] == '0' and b[i] == '0')
        {
            if (i + 1 > n or (a[i + 1] == '1' and b[i + 1] == '1'))
                ok = 1;
        }

        if (ok)
        {
            std::cout << "YES\n";
            return;
        }
    }

    std::cout << "NO\n";
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