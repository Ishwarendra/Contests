#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<int> a(n);

    std::map<int, int> mb;
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];
    for (int i = 0; i < m; i++)
    {
        int x;
        std::cin >> x;
        mb[x]++;
    }

    std::map<int, int> ele;
    int sum = 0;
    auto add = [&](int x)
    {
        ele[x]++;
        if (mb.contains(x) and ele[x] <= mb[x])
            sum++;
    };

    auto remove = [&](int x)
    {
        ele[x]--;
        if (mb.contains(x) and ele[x] < mb[x])
            sum--;
    };

    for (int i = 0; i < m - 1; i++)
        add(a[i]);

    int ans = 0;
    for (int i = m - 1; i < n; i++)
    {
        add(a[i]);
        ans += sum >= k;
        remove(a[i - m + 1]);
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