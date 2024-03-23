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
    
    std::string s;
    std::cin >> s;

    int n = std::size(s);
    std::vector suff(n + 1, std::array<int, 26>());
    for (int i = n - 1; i >= 0; i--)
    {
        suff[i][s[i] - 'a']++;
        for (int j = 0; j < 26; j++)
            suff[i][j] += suff[i + 1][j];
    }

    i64 ans = 0;
    int add = 0;
    for (int i = 0; i < n; i++)
    {
        for (int ch = 0; ch < 26; ch++)
        {
            if (ch == s[i] - 'a')
            {
                add |= suff[i + 1][ch] > 0;
                continue;
            }
            ans += suff[i + 1][ch];
        }
    }

    std::cout << ans + add;
    
    return 0;
}