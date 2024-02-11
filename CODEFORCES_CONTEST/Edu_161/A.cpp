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
    std::string a, b, c;
    std::cin >> n >> a >> b >> c;

    int ok = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == b[i] and b[i] == c[i])
            continue;
        if (a[i] != b[i] and (c[i] == a[i] or c[i] == b[i]))
            continue;
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