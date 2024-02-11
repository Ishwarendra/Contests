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

    std::vector<int> pref(n), suff(n);
    pref[0] = a[0] == 2;
    suff[n - 1] = a[n - 1] == 2;

    for (int i = 1; i < n; i++)
        pref[i] = pref[i - 1] + (a[i] == 2);
    for (int i = n - 2; i >= 0; i--)
        suff[i] = suff[i + 1] + (a[i] == 2);

    for (int i = 0; i < n - 1; i++)
    {
        if (pref[i] == suff[i + 1])
        {
            std::cout << i + 1 << "\n";
            return;
        }
    }

    std::cout << "-1\n";
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