#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, d;
    std::cin >> n >> d;

    std::vector<int> k(n), s(n);
    for (int i = 0; i < n; i++)
        std::cin >> k[i] >> s[i];

    std::queue<int> q;
    for (int i = 0; i < n; i++)
        q.emplace(i);

    // (time, -priority, when, node)
    std::set<std::tuple<int, int, int, int>> pq;
    pq.emplace(d + 1, 1, 0, -1);
    int count = 0, tot = 0;
    while (!q.empty())
    {
        auto uq = q.front();
        auto [tpq, priority, when, upq] = *std::begin(pq);
        tot++;

        if (-priority > k[uq] and tpq < tot)
        {
            pq.erase(std::begin(pq));

            if (tpq + s[upq] <= d)
                pq.emplace(tpq + s[upq], -k[upq], ++count, upq);
        }
        else
        {
            q.pop();
            if (tot + s[uq] <= d)
                pq.emplace(tot + s[uq], -k[uq], ++count, uq);
        }
    }

    std::cout << (tot > d ? -1 : tot) << "\n";
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