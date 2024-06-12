#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;
using i128 = __int128;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    i64 n;
    std::string s, t;
    std::cin >> n >> s >> t;

    const int sz = std::size(s);
    std::vector sum(sz, std::array<int, 26>());
    for (int i = 0; i < sz; i++)
    {
        sum[i][s[i] - 'a'] = 1;
        for (int j = 0; j < 26 and i > 0; j++)
            sum[i][j] += sum[i - 1][j];
    }

    for (auto ch : t)
    {
        if (sum.back()[ch - 'a'] == 0)
        {
            std::cout << 0;
            return 0;
        }
    }

    auto sum_ = [&](int x, i64 R)
    {
        if (R < 0)
            return 0LL;

        i64 tot = sum.back()[x];
        return (tot * (R / sz)) + sum[R - (R / sz) * sz][x]; 
    };
    
    auto count = [&](int ch, i64 L, i64 R)
    {
        if (R < L or R < 0 or L < 0)
            return 0LL;

        return sum_(ch, R) - sum_(ch, L - 1);
    };

    auto get = [&](i64 L, int ch, i64 need)
    {
        i64 tot = sum.back()[ch];
        i64 rem = count(ch, L % sz, sz - 1);

        auto getBestId = [&](int left, int right)
        {
            int st = L % sz;
            int ans = 0;
            while (left <= right)
            {
                int mid = std::midpoint(left, right);
                int cnt = sum[mid][ch] - (st ? sum[st - 1][ch] : 0);
                if (cnt >= need)
                    ans = mid, right = mid - 1;
                else
                    left = mid + 1;
            }

            return ans - st;
        };

        if (rem >= need)
            return L + getBestId(L % sz, sz - 1);

        need -= rem;
        L += sz - (L % sz);

        i64 x = std::max<i64>(0, need / tot - (need % tot == 0));

        if (L + i128(x) * sz >= n * sz)
            return -1LL;

        need -= x * tot;
        L += x * sz;

        assert(need != 0);
        return L + getBestId(0, sz - 1);
    };

    auto good = [&](i64 k)
    {
        i64 L = 0;
        i64 rem = k * std::ssize(t);

        for (auto ch : t)
        {
            int x = ch - 'a';
            i64 R = get(L, x, k);
            if (R >= n * sz or R == -1)
                return false;

            rem -= k;

            L = R + 1;
        }

        return true;
    };

    i64 left = 1, right = n * sz / std::ssize(t);
    i64 ans = 0;

    while (left <= right)
    {
        auto mid = std::midpoint(left, right);
        if (good(mid))
            ans = mid, left = mid + 1;
        else
            right = mid - 1;
    }

    std::cout << ans;

    return 0;
}