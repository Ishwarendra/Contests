#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

i64 C(int n, int r)
{
    if (r == 0)
        return 1;
    return n * C(n - 1, r - 1) / r;
}

void solve()
{
    int n, q;
    std::cin >> n >> q;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    std::sort(std::begin(a), std::end(a));
    std::vector<i64> val;
    i64 prev = 0;
    for (int i = 0; i < n; i++)
    {
        val.emplace_back(prev + C(n - i - 1, 2));
        prev = val.back();
    }

    while (q--)
    {
        i64 k;
        std::cin >> k;

        auto id = std::lower_bound(std::begin(val), std::end(val), k) - std::begin(val);
        std::cout << a[id] << "\n";
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