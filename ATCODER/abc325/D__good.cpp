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
    
    int n;
    std::cin >> n;

    std::vector<std::pair<i64, i64>> a(n);
    for (auto &[t, d] : a)
        std::cin >> t >> d;

    int ans = 0;
    auto getBit = [&](int x, int pos) { return x >> pos & 1; };
    for (int mask = 0; mask < (1 << n); mask++)
    {
        std::vector<std::pair<i64, i64>> temp;
        for (int i = 0; i < n; i++)
            if (getBit(mask, i)) temp.push_back(a[i]);

        int ok = 0;
        std::sort(std::begin(temp), std::end(temp));
        do
        {
            int sz = temp.size();
            i64 st = 0;
            int cnt = 0;

            for (int i = 0; i < sz; i++)
            {
                auto [t, d] = temp[i];
                if (st < t)
                    st = t;
                else if (st > t + d)
                    continue;

                st++;
                cnt++;
            }

            if (cnt == sz)
            {
                ok = 1;
                break;
            }

        } while (std::next_permutation(std::begin(temp), std::end(temp)));

        if (ok)
            ans = std::max(ans, __builtin_popcount(mask));
    }
    
    std::cout << ans;
    return 0;
}