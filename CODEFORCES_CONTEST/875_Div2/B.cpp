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

    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];
    for (int i = 0; i < n; i++)
        std::cin >> b[i];

    auto get = [&](std::vector<int> &c)
    {
        std::map<int, int> ans;
        int cnt = 1;
        for (int i = 1; i < n; i++)
        {
            if (c[i] == c[i - 1])
                cnt++;
            else
            {
                ans[c[i - 1]] = std::max(ans[c[i - 1]], cnt);
                cnt = 1;
            }
        }

        ans[c.back()] = std::max(ans[c.back()], cnt);
        return ans;
    };

    auto m1 = get(a);
    auto m2 = get(b);
    
    int ans = 0;
    for (int i = 0; i < 2 * n + 1; i++)
        ans = std::max(ans, m1[i] + m2[i]);

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