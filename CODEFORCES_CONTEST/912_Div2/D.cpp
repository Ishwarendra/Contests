#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, q;
    std::cin >> n >> q;

    std::vector<i64> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    auto getBit = [&](i64 x, int pos) { return x >> pos & 1LL; };

    while (q--)
    {
        i64 k;
        std::cin >> k;

        i64 ans = 0;
        auto b = a;
        for (int pos = 60; pos >= 0; pos--)
        {
            i64 need = 0;
            for (int i = 0; i < n; i++)
            {
                if (!getBit(a[i], pos))
                {
                    i64 new_ai = a[i] & ((1LL << (pos + 1)) - 1);
                    need += (1LL << pos) - new_ai;
                    assert(new_ai < (1LL << pos));

                    if (need > k)
                        break;
                }
            }

            if (need <= k)
            {
                k -= need;
                for (int i = 0; i < n; i++)
                {
                    if (!getBit(a[i], pos))
                        a[i] = (1LL << pos);
                }

                ans |= (1LL << pos);
            }
        }

        std::swap(a, b);
        std::cout << ans << "\n";
    }

    return 0;
}