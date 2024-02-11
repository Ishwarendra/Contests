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

    constexpr int inf = 1e9 + 10;

    int last = a[0];
    std::string ans = "1";
    int i = 1;
    while (i < n)
    {
        if (a[i] >= last)
            ans += '1', last = a[i];
        else if (a[i] > a[0])
            ans += '0';
        else
            break;
        i++;
    }

    last = -inf;
    while (i < n)
    {
        if (a[i] <= a[0] and a[i] >= last)
            last = a[i], ans += '1';
        else
            ans += '0';
        i++;
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