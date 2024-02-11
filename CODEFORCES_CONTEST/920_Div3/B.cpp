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
    std::string s, t;
    std::cin >> n >> s >> t;

    int ans = 0, extra = 0;
    for (int i = 0; i < n; i++)  
    {
        if (s[i] != t[i])
        {
            if (s[i] == '1' and t[i] == '0')
                extra++;
            else
                ans++;
        }
    }

    std::cout << std::max(extra, ans) << "\n";
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