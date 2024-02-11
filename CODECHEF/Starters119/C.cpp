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

    auto getBit = [&](int x, int pos) { return x >> pos & 1; };

    auto f = [&](auto &&self, int l, int r) -> i64
    {
        if (l > r)
            return 0;

        if (l == r)
            return 1;

        int m = (l + r) / 2;
        i64 ans = self(self, l, m);
        ans += self(self, m + 1, r);

        std::array<int, 30> one{}, zero{};
        std::array<int, 30> cnt[4]{};
        for (int i = m; i >= l; i--)
        {
            for (int bit = 0; bit < 30; bit++)   
            {
                if (getBit(a[i], bit))
                    one[bit] ^= 1;
                else
                    zero[bit] = 1;
            }

            int id = 0;
            int o = 0, z = 0;
            for (int bit = 0; bit < 30; bit++)
            {
                o &= one[bit];
                z |= 
            }
        }
    };
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