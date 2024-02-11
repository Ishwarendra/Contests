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

    constexpr int N = 1e3 + 1;
    std::vector<int> a(N, -1);
    for (int i = 0; i < n; i++)  
    {
        int x;
        std::cin >> x;
        a[x] = i + 1;
    }

    int ans = -1;

    for (int i = 1; i < N; i++)
    {
        for (int j = 1; j < N; j++)
        {
            if (a[i] == -1 or a[j] == -1)
                continue;

            if (std::gcd(i, j) == 1)
                ans = std::max(ans, a[i] + a[j]);
        }
    }

    std::cout << ans << "\n";
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