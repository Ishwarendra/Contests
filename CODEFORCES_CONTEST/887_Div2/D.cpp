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
    std::vector<int> adj[n];

    for (int i = 0; i < n; i++)  
        std::cin >> a[i];

    std::vector<int> ord(n);
    std::iota(std::begin(ord), std::end(ord), 0);

    std::sort(std::begin(ord), std::end(ord), [&](int x, int y)
    {
        return a[x] < a[y];
    });

    int l = 0, r = n - 1;
    int sub = 0;
    std::vector<int> b(n);

    int max = n;
    while (l <= r)
    {
        if (a[ord[l]] - sub == 0)
            b[ord[l]] = -max, l++;
        else if (a[ord[r]] - sub == max)
            b[ord[r]] = max, r--, sub++;
        else
        {
            std::cout << "NO\n";
            return;
        }

        max--;
    }

    std::cout << "YES\n";
    for (int i = 0; i < n; i++)
        std::cout << b[i] << " \n"[i == n - 1];
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