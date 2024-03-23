#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    std::string s;
    std::cin >> n >> s;

    std::vector<int> p(n);
    for (int i = 0; i < n; i++)
    {
        p[i] = s[i] - '0';
        if (i)
            p[i] += p[i - 1];
    }

    auto ones = [&](int l, int r) { return p[r] - (l ? p[l - 1] : 0); };
    auto zeroes = [&](int l, int r) { return r - l + 1 - ones(l, r); };

    std::array<int, 2> ans{int(1e9), -1};
    if (zeroes(0, n - 1) >= (n + 1) / 2)
        ans = { std::abs(n - 2 * n), n };
    if (ones(0, n - 1) >= (n + 1) / 2)
        ans = std::min(ans, std::array { std::abs(n - 0), 0 });

    for (int i = 0; i < n - 1; i++)
    {
        int left = (i + 2) / 2 <= zeroes(0, i);
        int right = (n - i) / 2 <= ones(i + 1, n - 1);

        if (left and right)
            ans = std::min(ans, std::array { std::abs(n - 2 * i - 2), i + 1 });
    }

    std::cout << ans[1] << "\n";
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