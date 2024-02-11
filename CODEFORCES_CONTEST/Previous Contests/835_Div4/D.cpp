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

    a.resize(std::unique(std::begin(a), std::end(a)) - std::begin(a));
    int count = 0;
    for (int i = 0; i < std::size(a); i++)
    {
        int can = 1;
        if (i - 1 >= 0 and a[i - 1] <= a[i])
            can = 0;
        if (i + 1 < std::size(a) and a[i + 1] <= a[i])
            can = 0;

        if (can)
            count++;
    }

    std::cout << (count == 1 ? "YES\n" : "NO\n");
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