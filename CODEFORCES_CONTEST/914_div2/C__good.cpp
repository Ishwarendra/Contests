#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, k;
    std::cin >> n >> k;

    std::vector<i64> a(n);
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];

    i64 ans = 1e9;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            i64 del = std::abs(a[i] - a[j]);
            a.emplace_back(del);

            for (int k = 0; k <= n; k++)
            {
                for (int p = 0; p <= n; p++)
                {
                    if (k == p)
                        continue;

                    a.emplace_back(std::abs(a[k] - a[p]));
                    ans = std::min(ans, *std::min_element(std::begin(a), std::end(a)));
                    if (ans == 98902657)
                    {
                        print(i, j, k, p, a[i], a[j],a[k], a[p])
                    }
                    a.pop_back();
                }       
            }

            a.erase(std::find(std::begin(a), std::end(a), del));
        }
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