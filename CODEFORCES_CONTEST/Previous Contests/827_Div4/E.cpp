#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(n);
    std::map<int, int> first;
    for (int i = 0; i < n; i++)  
    {
        std::cin >> a[i];

        auto it = first.lower_bound(a[i]);
        if (it == std::end(first))
            first[a[i]] = i;
    }

    std::vector<i64> pref(n + 1, 0);

    for (int i = 1; i <= n; i++)
        pref[i] = pref[i - 1] + a[i - 1];

    while (m--)
    {
        int k;
        std::cin >> k;

        auto index = first.upper_bound(k);
        int id;

        if (index == std::end(first))
            id = n;
        else
            id = index->second;
        
        std::cout << pref[id] << " ";
    }

    std::cout << "\n";
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