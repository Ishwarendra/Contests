#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, k;
    std::string s;
    std::cin >> n >> k >> s;

    std::array<int, 26> lower{}, upper{};
    int ans = 0;
    for (auto &ch : s) 
    {
        if ('a' <= ch and ch <= 'z')
            lower[ch - 'a']++;
        else 
            upper[ch - 'A']++;
    }

    for (int i = 0; i < 26; i++)
    {
        auto [min, max] = std::minmax(lower[i], upper[i]);
        if (k >= (max - min) / 2)
            ans += (min + max) / 2, k -= (max - min) / 2;
        else if (k != 0)
        {
            ans += min + k;
            k = 0;
        }
        else
            ans += min;
    }

    std::cout << ans << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}