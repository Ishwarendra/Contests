#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(n + m + 1), b(n + m + 1);
    for (int i = 0; i <= n + m; i++)
        std::cin >> a[i];
    for (int i = 0; i <= n + m; i++)
        std::cin >> b[i];

    std::vector<int> type(n + m + 1), p, t;
    int pcnt = 0, tcnt = 0, lastp = -1, lastt = -1;
    i64 sum = 0;
    for (int i = 0; i < n + m; i++)
    {
        if (a[i] > b[i])
            p.emplace_back(i);
        else
            t.emplace_back(i);
        
        if ((a[i] > b[i] and pcnt < n) || tcnt == m)
            pcnt++, sum += a[i], type[i] = 0;
        else
            tcnt++, sum += b[i], type[i] = 1;
        
        if (lastp == -1 and pcnt == n)
            lastp = i;
        if (lastt == -1 and tcnt == m)
            lastt = i;
    }
    
    for (int i = 0; i < n + m; i++)
    {
        if (type[i])
        {
            // want to test
            auto id = std::upper_bound(std::begin(t), std::end(t), lastt) - std::begin(t);
            if (id >= std::size(t))
                std::cout << sum + b.back() - b[i] << " ";
            else
                std::cout << sum + b[t[id]] + a.back() - a[t[id]] - b[i] << " ";
        }
        else
        {
            auto id = std::upper_bound(std::begin(p), std::end(p), lastp) - std::begin(p);
            if (id >= std::size(p))
                std::cout << sum + a.back() - a[i] << " ";
            else
                std::cout << sum + a[p[id]] + b.back() - a[i] - b[p[id]] << " ";
        }
    }
    
    std::cout << sum << "\n";
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