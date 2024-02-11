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
    std::cin >> n;

    int odd = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        std::cin >> a;
        odd += a % 2;
    }

    std::cout << (odd % 2 ? "NO\n" : "YES\n");
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