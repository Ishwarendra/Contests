#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, c, d;
    std::cin >> n >> c >> d;

    std::vector<int> a;
    std::map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        int x;
        std::cin >> x;
        m[x]++;
    }

    i64 ans = 0;
    for (auto [num, f] : m)
    {
        a.emplace_back(num);
        ans += 1LL * (f - 1) * c;
    }

    n = std::size(a);
    i64 base = ans;

    ans += 1LL * (a.back() - n) * d;
    for (int i = n - 1; i >= 0; i--)
    {
        i64 cur_ans = base;
        cur_ans += 1LL * c * (n - i);

        if (i == 0)
        {
            cur_ans += d;
            ans = std::min(ans, cur_ans);
            continue;
        }

        int missing = a[i - 1] - i;

        cur_ans += 1LL * missing * d;
        ans = std::min(ans, cur_ans);
    }

    std::cout << ans << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}