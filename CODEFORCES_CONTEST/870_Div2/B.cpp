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

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)          
        std::cin >> a[i];

    int i = 0, j = n - 1;
    int g = 0;

    while (i < j)
    {
        int d = std::abs(a[i] - a[j]);
        g = std::gcd(g, d);
        i++, j--;
    }

    std::cout << g << "\n";
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