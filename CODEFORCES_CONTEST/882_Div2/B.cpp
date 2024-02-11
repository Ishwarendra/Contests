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

    int x = a[0];
    for (int i = 1; i < n; i++)
        x &= a[i];

    if (x > 0)
        std::cout << "1\n";
    else
    {
        int ans = 0;
        for (int i = 0; i < n; )
        {
            int cur = a[i];
            int j = i;

            while (j < n and cur > 0)
            {
                cur &= a[j];
                j++;
            }

            i = j + (a[i] == 0);
            ans += (cur == 0);
        }

        std::cout << ans << "\n";
    }
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