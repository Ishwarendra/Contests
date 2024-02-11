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

    int need = n / 2 + 1;
    std::string ans(n, 'P');

    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == 'R')
            need--;
    }

    for (int i = n - 1; i >= 0 and need > 0; i--)
    {
        if (s[i] == 'P')
            ans[i] = 'S', need--;
        if (s[i] == 'S')
            ans[i] = 'R', need--;
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