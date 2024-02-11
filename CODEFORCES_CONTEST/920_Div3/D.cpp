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

    std::vector<int> a(n), b(m);
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];

    for (int i = 0; i < m; i++)
        std::cin >> b[i];

    std::sort(std::begin(a), std::end(a));
    std::sort(std::begin(b), std::end(b));

    auto get = [&](int i, int j) { return std::abs(a[i] - b[j]); };

    int st = 0, en = m - 1;
    i64 ans = 0;

    for (int i = 0, j = n - 1; i <= j; )
    {
        if (std::max(get(i, st), get(i, en)) > std::max(get(j, st), get(j, en)))
        {
            if (get(i, st) > get(i, en))
                ans += get(i++, st++);
            else
                ans += get(i++, en--);
        }
        else
        {
            if (get(j, st) > get(j, en))
                ans += get(j--, st++);
            else
                ans += get(j--, en--); 
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