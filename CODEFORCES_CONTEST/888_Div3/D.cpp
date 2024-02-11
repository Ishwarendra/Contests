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

    std::vector<i64> a(n - 1);  
    for (int i = 0; i < n - 1; i++)
        std::cin >> a[i];

    if (a.back() > n * (n + 1LL) / 2)
        std::cout << "NO\n";
    else if (a.back() < n * (n + 1LL) / 2)
    {
        a.emplace_back(n * (n + 1LL) / 2);
        std::vector<i64> p(n);
        p[0] = a[0];

        for (int i = n - 1; i >= 0; i--)
            p[i] = a[i] - (i ? a[i - 1] : 0LL);

        std::sort(std::begin(p), std::end(p));
        for (int i = 0; i < n; i++)
        {
            if (p[i] != i + 1)
            {
                std::cout << "NO\n";
                return;
            }
        }

        std::cout << "YES\n";
    }
    else
    {
        std::vector<int> vis(n);
        int miss_id = -1;
        for (int i = n - 2; i >= 0; i--)
        {
            i64 d = a[i];
            if (i)
                d -= a[i - 1];
            if (d <= 0 or d > n)
            {
                if (miss_id != -1)
                {
                    std::cout << "NO\n";
                    return;
                }

                miss_id = i;
                continue;
            }

            if (!vis[d - 1])
                vis[d - 1] = 1;
            else
                miss_id = i;
        }

        if (std::accumulate(std::begin(vis), std::end(vis), 0) != n - 2)
            std::cout << "NO\n";
        else if (miss_id == 0)
        {
            int sum = 0;
            for (int i = 0; i < n; i++)
            {
                if (!vis[i])
                    sum += i + 1;
            }
            
            if (sum == a.front())
                std::cout << "YES\n";
            else
                std::cout << "NO\n";
        }
        else
        {
            int x = -1, y = -1;
            for (int i = 0; i < n; i++)
            {
                if (!vis[i])
                {
                    if (x == -1)
                        x = i + 1;
                    else
                        y = i + 1;
                }
            }

            i64 d = a[miss_id] - a[miss_id - 1];
            for (int i = 0; i < 2; i++)
            {
                std::swap(x, y);
                int s = d - (x - y) / 2;

                if (s > 0)
                {
                    std::cout << "YES\n";
                    return;
                }
            }

            std::cout << "NO\n";
        }
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