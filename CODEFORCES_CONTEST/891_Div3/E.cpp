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
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];

    std::vector<int> ord(n);
    std::iota(std::begin(ord), std::end(ord), 0);
    std::sort(std::begin(ord), std::end(ord), [&](int i, int j)
    {
        return a[i] < a[j];
    });

    std::vector<i64> p(n);
    p[ord[0]] = a[ord[0]];
    for (int i = 1; i < n; i++)
        p[ord[i]] = p[ord[i - 1]] + a[ord[i]];

    auto sum = [&](int l, int r)
    {   
        if (l > r)
            return 0LL;

        return p[ord[r]] - (l ? p[ord[l - 1]] : 0LL);
    };

    std::vector<i64> ans(n);
    for (int i = 0; i < n; i++)
    {
        ans[ord[i]] = 1LL * i * a[ord[i]] - sum(0, i - 1) + i;
        ans[ord[i]] += sum(i, n - 1) - 1LL * a[ord[i]] * (n - i) + n - i;
    }

    for (int i = 0; i < n; i++)
        std::cout << ans[i] << " \n"[i == n - 1];
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