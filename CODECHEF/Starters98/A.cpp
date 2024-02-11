#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, m;
    std::cin >> n >> m;

    i64 sum = 0;
    for (int i = 0; i < m; i++)
    {
        int c;
        std::cin >> c;
        sum += c;
    }

    if ((sum + n - 1) / n < m)
        std::cout << "0\n";
    else
    {
        int ans = sum % n;
        if (ans == 0)
            ans = n;

        std::cout << ans << "\n";
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