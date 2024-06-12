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
    std::cin >> n;
    
    std::vector<int> b(n);
    for (int i = 0; i < n; i++)  
        std::cin >> b[i];
    
    std::vector<int> a(n - 1);
    for (int i = 0; i < n - 1; i++)
        a[i] = std::gcd(b[i], b[i + 1]);
    
    int pref = 0, suff = n - 2;
    while (pref < n - 2 and a[pref] <= a[pref + 1])
        pref++;
    while (suff > 0 and a[suff - 1] <= a[suff])
        suff--;
    
    int ans = suff <= 1 or pref >= n - 3;
    for (int i = 1; i < n - 1; i++)
    {
        if (pref < i - 2 or suff > i + 1)
            continue;
        
        int cur = std::gcd(b[i - 1], b[i + 1]);
        if ((i - 2 < 0 or a[i - 2] <= cur) and (i + 1 >= n - 1 or cur <= a[i + 1]))
            ans = 1;
    }

    std::cout << (ans ? "YES\n" : "NO\n");
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