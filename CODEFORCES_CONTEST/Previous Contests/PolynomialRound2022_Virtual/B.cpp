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

    std::vector<int> a(m);  
    for (int i = 0; i < m; i++)
        std::cin >> a[i];

    std::sort(std::rbegin(a), std::rend(a));

    int group = (n + k - 1) / k; 
    int count = 0;
    for (int i = 0; i < m; i++)
    {
        if (a[i] > group)
        {
            std::cout << "NO\n";
            return;
        }
        else if (a[i] == group)
            count++;
    }

    if (count > n - 1LL * ((n - 1) / k) * k)
        std::cout << "NO\n";
    else
        std::cout << "YES\n";
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