#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::string s;
    std::cin >> n >> s;

    std::vector<int> c(n);
    for (int i = 0; i < n; i++)
        std::cin >> c[i];

    std::vector<i64> p01(n + 1), p10(n + 1);
    for (int i = 0; i < n; i++)
    {
        p01[i + 1] = p01[i], p10[i + 1] = p10[i];
        if (i % 2)
        {
            p01[i + 1] += (s[i] == '0') * c[i];
            p10[i + 1] += (s[i] == '1') * c[i];
        }
        else
        {
            p10[i + 1] += (s[i] == '0') * c[i];
            p01[i + 1] += (s[i] == '1') * c[i];
        }
    }

    auto sum = [&](auto &p, int l, int r) 
    { 
        if (l > r)
            return 0LL;
        return p[r] - p[l - 1]; 
    };

    i64 ans = std::numeric_limits<i64>::max();
    for (int i = 1; i < n; i++)
    {
        for (int ch1 = 0; ch1 < 2; ch1++)
    {
            i64 cur = 0, len = (i - 1) & 1;
            if (ch1 ^ len)
                cur += sum(p10, 1, i - 1) + sum(p01, i + 2, n);
            else
                cur += sum(p01, 1, i - 1) + sum(p10, i + 2, n);

            if (s[i - 1] - '0' != ch1)
                cur += c[i - 1];
            if (s[i] - '0' != ch1)
                cur += c[i];

            ans = std::min(ans, cur);
        }
    }

    std::cout << ans;
    
    return 0;
}