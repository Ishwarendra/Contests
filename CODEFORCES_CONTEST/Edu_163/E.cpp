#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, k;
    std::cin >> n >> k;
    
    auto get = [&](int len)
    {
        int cnt = 1, num = 1;
        std::vector<int> a(n), c(n);
        for (int i = 0; i < n; i += len)
        {
            int en = std::min(n, i + len);
            for (int j = i; j < en; j++)
                c[j] = cnt;

            int mid = (i + en) / 2;
            for (int j = mid; j < en; j++)
                a[j] = num++;
            for (int j = i; j < mid; j++)
                a[j] = num++;

            for (int u = i; u < en; u++)
            {
                for (int v = u + 1; v < en; v++)
                {
                    if (std::abs(u - v) + std::abs(a[u] - a[v]) > k)
                        return false;
                }
            }

            cnt++;
        }

        for (int i = 0; i < n; i++)
            std::cout << a[i] << " \n"[i == n - 1];

        std::cout << (n + len - 1) / len << "\n";

        for (int i = 0; i < n; i++)
            std::cout << c[i] << " \n"[i == n - 1];

        return true;
    };

    for (int i = n; i >= 1; i--)
    {
        if (get(i))
            return;
    }

    assert(false);
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