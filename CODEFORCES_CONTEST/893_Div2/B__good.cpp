#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, m, d;
    std::cin >> n >> m >> d;

    std::vector<int> a(n + 1);
    std::vector<int> b;
    for (int i = 0; i < m; i++)  
    {
        int x;
        std::cin >> x;
        a[x]++;
        b.emplace_back(x);
    }

    auto get = [&](int skip)
    {
        int ate = 0;
        int ans = 0, last = 0;

        for (int i = 1; i <= n; i++)
        {
            if (ate == 0)
            {
                ans++;
                ate = 1;
                last = i;
                continue;
            }

            if (i != skip and a[i])
                ans++, last = i;
            else if (i - last == d)
                ans++, last = i;
        }

        return ans;
    };

    int min = n, cnt = 0;
    for (int i = 0; i < m; i++)
        min = std::min(min, get(b[i]));

    for (int i = 0; i < m; i++)
        cnt += min == get(b[i]);

    std::cout << min << " " << cnt << "\n";
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