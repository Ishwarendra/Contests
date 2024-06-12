#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    i64 k;
    std::cin >> n >> k;
    
    std::vector<i64> a(n + 1);
    for (int i = 1; i <= n; i++)  
        std::cin >> a[i];
    
    std::sort(std::begin(a), std::end(a));
    std::vector<i64> pref(n + 1);
    for (int i = 1; i <= n; i++)
        pref[i] = pref[i - 1] + a[i];
    
    int id = n;
    while (id >= 1)
    {
        if (a[id] * id - pref[id] <= k)
            break;
        id--;
    }
    
    for (int i = 1; i <= id; i++)
    {
        if (a[i] < a[id])
        {
            k -= a[id] - a[i];
            a[i] = a[id];
        }
    }

    std::cout << (a[id] + k / id) * n + (k % id) + 1 - id << "\n";
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