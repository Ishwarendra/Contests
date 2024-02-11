#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr int N = 1 << 15;
std::vector<int> palin;

void solve()
{
    int n;
    std::cin >> n;

    std::vector a(n, 0);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    std::array<int, N> cnt{};
    i64 ans = 0;
    for (int i = 0; i < n; i++)
    {
        cnt[a[i]]++;
        for (auto p : palin)
            ans += cnt[p ^ a[i]];
    }

    std::cout << ans << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    auto isPalin = [&](int x)
    {
        auto s = std::to_string(x);
        return s == std::string(std::rbegin(s), std::rend(s));
    };

    for (int i = 0; i < N; i++)
    {
        if (isPalin(i))
            palin.emplace_back(i);
    }

    int t;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}