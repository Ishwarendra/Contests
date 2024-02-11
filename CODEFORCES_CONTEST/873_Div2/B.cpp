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

    int gcd = 0;
    std::vector<int> a(n), pos(n);
    for (int i = 0; i < n; i++)  
    {
        std::cin >> a[i];
        a[i]--;
        pos[a[i]] = i;
    }

    for (int i = 0; i < n; i++)
    {
        if (a[i] == i)
            continue;
        gcd = std::gcd(gcd, std::abs(i - pos[i]));
    }

    std::cout << gcd << "\n";
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