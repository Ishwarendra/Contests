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

    std::map<int, int> m;
    for (int i = 0; i < n; i++)  
    {
        int x;
        std::cin >> x;
        m[x]++;
    }

    for (int x = 0; x <= n; x++)
    {
        int liar = 0;
        for (int i = x + 1; i <= n; i++)
            liar += (m.contains(i) ? m[i] : 0);

        if (liar == x)
        {
            std::cout << x << "\n";
            return;
        }
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