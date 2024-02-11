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

    int ok = (n == 1 and s[0] == '0');
    for (int i = 0; i < n - 1; i++)  
    {
        if (s[i] != s[i + 1] or s[i] == '0')
            ok = 1;
    }

    std::cout << (ok ? "YES\n" : "NO\n");
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