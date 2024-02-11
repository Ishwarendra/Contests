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

    auto factor = [&](int x)
    {
        std::vector<int> f;
        for (int i = 1; 1LL * i * i <= x; i++)
        {
            if (x % i == 0)
            {
                f.emplace_back(i);
                if (i * i != x)
                    f.emplace_back(x / i);
            }
        }

        return f;
    };

    auto f = factor(n);
    std::sort(std::begin(f), std::end(f));

    auto ans = std::string(n, '.');
    for (int i = 0; i < n; i++)
    {
        std::array<int, 26> mex{};
        for (auto y : f)
        {
            if (i - y < 0 or i - 1 < 0)
                break;

            mex[ans[i - 1] - 'a'] = mex[ans[i - y] - 'a'] = 1;
        }

        int m = 0;
        while (m < 26 and mex[m]) m++;

        assert(m < 26);
        ans[i] = char(m + 'a');
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