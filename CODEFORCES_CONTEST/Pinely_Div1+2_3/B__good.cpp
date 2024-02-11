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

    std::vector<i64> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];
    
    auto getBit = [&](i64 x, int pos) { return x >> pos & 1LL; };
    for (int bit = 0; bit <= std::__lg(i64(1e17)); bit++)
    {
        int cnt = 0;
        for (int i = 0; i < n; i++)
            cnt += getBit(a[i], bit);

        if (cnt == n)
            continue;
        else
        {
            std::cout << (1LL << (bit + 1)) << "\n";
            return;
        }
    }

    // assert(false);
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