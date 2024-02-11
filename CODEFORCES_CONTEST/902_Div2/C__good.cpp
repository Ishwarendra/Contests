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

    int ans = 0;
    std::vector<int> temp(n + 1);
    for (int x = m; x >= 0; x--)
    {
        temp[n] = x;
        for (int i = n - 1; i >= 0; i--)
            temp[i] = (temp[i + 1] % (i + 1));
        auto s= std::set(std::begin(temp), std::end(temp));
        if (s.size() == k)
        {
            ans++;
        }
    }

    std::cout << ans << "\n";
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