#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

auto getBit(auto x, auto pos)
{
    return (x >> pos) & 1;
}

void solve()
{
    int n, k;
    std::cin >> n >> k;

    std::string a, b;
    std::cin >> a >> b;

    std::string c = a;
    std::sort(std::begin(c), std::end(c));
    c.resize(std::unique(std::begin(c), std::end(c)) - std::begin(c));

    int count = std::size(c);
    i64 ans = 0;

    // pick character i and change it to whatever you want
    for (int mask = 0; mask < (1 << count); mask++)
    {
        if (__builtin_popcount(mask) > k)
            continue;

        // std::vector<int> same(n);
        int same[n]{};
        std::array<int, 26> changeable{};

        for (int i = 0; i < count; i++)
        {
            if (getBit(mask, i))
                changeable[c[i] - 'a'] = 1;
        }

        for (int i = 0; i < n; i++)
        {
            if (a[i] == b[i] or changeable[a[i] - 'a'])
                same[i] = 1;
        }

        int num = 1;
        i64 cur_ans = 0;
        for (int i = 0; i < n; i++)
        {   
            if (same[i])
                cur_ans += num++;
            else
                num = 1;
        }

        ans = std::max(ans, cur_ans);
    }

    std::cout << ans << '\n';
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