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

    std::vector in(n, std::array<int, 4>());
    for (auto &[l, r, a, b] : in)  
        std::cin >> l >> r >> a >> b;

    std::sort(std::begin(in), std::end(in), [&](auto &a, auto &b)
        {
            return std::array{a[0], a[3]} < std::array{b[0], b[3]};
        });

    int q;
    std::cin >> q;
    std::vector<std::pair<int, int>> qry(q);
    for (int i = 0; i < q; i++)
    {
        std::cin >> qry[i].first;
        qry[i].second = i;
    }

    int pos = 0;
    std::vector<int> ans(q);
    std::sort(std::begin(qry), std::end(qry));
    for (int i = 0; i < q; i++)
    {
        auto [x, id] = qry[i]; 
        ans[id] = x;
        if (i > 0)
            ans[id] = std::max(ans[id], ans[qry[i - 1].second]);

        while (pos < n and in[pos][0] <= x)
            x = std::max(x, in[pos][3]), pos++;
        
        ans[id] = std::max(ans[id], x);
    }

    for (int i = 0; i < q; i++)
        std::cout << ans[i] << " \n"[i == q - 1];
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