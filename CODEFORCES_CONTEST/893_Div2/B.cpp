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

    std::vector<int> a(m);
    for (int i = 0; i < m; i++)  
        std::cin >> a[i];

    if (m == 1)
    {
        std::cout << 1 + (n - 1) / d << " 1\n";
        return;
    }

    int add = 0;
    if (a.front() != 1)
        a.insert(std::begin(a), 1), add = 1;
    a.emplace_back(n + 1);

    i64 ans = 0;

    auto f = [&](int x, int y)
    {
        return 1 + (y - x - 1) / d;
    };

    for (int i = 1; i < std::size(a); i++)
        ans += f(a[i - 1], a[i]);

    std::array<i64, 2> best{n, 0};
    for (int i = 1; i + 1 < std::size(a); i++)
    {
        i64 cur_ans = ans;
        cur_ans -= f(a[i - 1], a[i]);
        cur_ans -= f(a[i], a[i + 1]);
        cur_ans += f(a[i - 1], a[i + 1]);

        best[0] = std::min(best[0], cur_ans);
    }

    for (int i = 1; i + 1 < std::size(a); i++)
    {
        i64 cur_ans = ans;
        cur_ans -= f(a[i - 1], a[i]);
        cur_ans -= f(a[i], a[i + 1]);
        cur_ans += f(a[i - 1], a[i + 1]);

        if (cur_ans == best[0])
            best[1]++;
    }

    if (!add)
        best[1] += best[0] == ans;
    
    std::cout << best[0] << " " << best[1] << "\n";
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