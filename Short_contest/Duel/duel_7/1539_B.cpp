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
    std::string s;
    std::cin >> n >> q >> s;

    std::vector a(n + 1, std::vector<int>(26));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 26; j++)
            a[i][j] = a[i - 1][j] + (s[i - 1] - 'a' == j);
    }

    while (q--)
    {
        int l, r;
        std::cin >> l >> r;

        i64 ans = 0;
        std::vector<int> cnt(26);

        for (int i = 0; i < 26; i++)
            cnt[i] = a[r][i] - a[l - 1][i];

        for (int i = 0; i < 26; i++)
            ans += (i + 1) * 1LL * cnt[i];

        std::cout << ans << "\n";
    }
    
    return 0;
}