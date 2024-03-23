#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    std::string s;
    std::cin >> s;

    int n = std::size(s);
    std::vector dp(n, std::vector(n, 0));

    auto equal = [&](char ch1, char ch2)
    {
        return ch1 == ch2 || ch1 == '?' || ch2 == '?';
    };

    std::vector pref(n, std::vector(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            pref[i][j] = equal(s[i], s[j]);
            if (i and j)
                pref[i][j] += pref[i - 1][j - 1];
        }
    }

    auto check = [&](int i1, int i2, int len)
    {
        int sub = 0;
        if (i1 and i2)
            sub = pref[i1 - 1][i2 - 1];

        return pref[i1 + len - 1][i2 + len - 1] - sub == len;
    };

    int ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (equal(s[i], s[i + 1]))
            ans = 2;
    }
    
    for (int len = 4; len <= n; len += 2)
    {
        for (int i = 0; i + len - 1 < n; i++)
        {
            int j = i + len - 1;

            int i1 = i;
            int i2 = j - len / 2 + 1;

            if (equal(s[i + len / 2 - 1], s[j]) and check(i1, i2, len / 2 - 1))
                ans = std::max(ans, len);
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