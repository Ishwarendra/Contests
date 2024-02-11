#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    std::function<i64(int, int)> C = [&](int n, int r) -> i64
    {
        if (n < r)
            return 0;
        if (r == 0)
            return 1;

        return n * C(n - 1, r - 1) / r;
    };

    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(n), freq(n + m + 1);
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        freq[a[i]] = m + 1;
    }

    for (int i = 0; i < m; i++)
    {
        int p, v;
        std::cin >> p >> v;
        p--;

        if (a[p] == v)
            continue;

        freq[a[p]] -= (m - i);
        freq[v] += (m - i);
        a[p] = v;
    }

    i64 ans = C(m + 1, 2) * 2 * n;
    
    for (int i = 0; i < n + m + 1; i++)
        ans -= C(freq[i], 2);

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