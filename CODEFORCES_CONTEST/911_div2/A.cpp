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
    std::string s;
    std::cin >> n >> s;  

    int max = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '#')
            continue;

        int j = i;
        while (j < n and s[j] == '.')
            j++;

        int len = j - i;
        max = std::max(max, len);
        ans += std::min(2, len);
        i = j;
    }

    if (max > 2)
        ans = 2;

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