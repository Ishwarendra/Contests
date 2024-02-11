#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<int> a(n), b(m);
    std::map<int, int> f;

    for (int i = 0; i < n; i++)  
    {
        std::cin >> a[i];
        f[a[i]] = 1;
    }

    for (int i = 0; i < m; i++)
    {
        std::cin >> b[i];
        if (!f.contains(b[i]))
            f[b[i]] = -1;
        else if (f[b[i]] == 1)
            f[b[i]] = 2;
    }

    int one = 0, minus = 0;
    for (int i = 1; i <= k; i++)
    {
        if (!f.contains(i))
        {
            std::cout << "NO\n";
            return;
        }

        if (f[i] == 1)
            one++;
        else if (f[i] == -1)
            minus++;
    }
    
    std::cout << (one * 2 <= k and minus * 2 <= k ? "YES\n" : "NO\n");
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