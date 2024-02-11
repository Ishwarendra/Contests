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

    std::vector<int> p(n + 1);
    for (int i = 0; i < n; i++)
        p[i + 1] = p[i] ^ a[i];

    i64 ans = 0;
    std::map<int, i64> max_id;
    max_id[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        if (max_id.contains(p[i]))
            ans += max_id[p[i]];
        max_id[p[i]] += i;
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