#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    std::string s;
    std::cin >> s;

    if (s == "^")
    {
        std::cout << "1\n";
        return;
    }

    if (s.back() == '_')
        s += '_';

    int n = std::size(s);
    int ans = 0;

    for (int i = 0; i < n; i++)    
    {
        if (s[i] == '_')
        {
            if (i - 1 < 0 or s[i - 1] == '_')
                ans++;
        }
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