#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

int sqroot(int x)
{
    const int s = 3;
    int l = std::sqrt(x) - s, r = std::sqrt(x) + s;
    for (int i = std::max(l, 0); i <= r; i++)
    {
        if (1LL * i * i == x)
            return i;
    }

    return l + s;
}

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    std::sort(std::begin(a), std::end(a));

    std::map<i64, int> m;
    for (int i = 0; i < n; i++)
        m[a[i]]++;

    i64 ans = 0;
    for (auto &[num, f] : m)
        ans += 1LL * f * (f - 1) * (f - 2);

    for (int i = 0; i < n; i++)
    {
        for (int b = 1; b * b * b <= a[i]; b++)
        {
            if (a[i] % (b * b) == 0 and b > 1)
                ans += m[a[i] / b] * m[a[i] / b / b];

            int b_dash = sqroot(a[i] / b);
            if (a[i] % b || b_dash == 1 || 1LL * b * b_dash * b_dash != a[i])
                continue;
            if (a[i] / b / b == b)
                continue;

            ans += 1LL * m[b] * m[1LL * b * b_dash];
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