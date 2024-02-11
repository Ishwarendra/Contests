#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr int N = 1e6 + 1;
std::array<int, N> pref{}, suff{};

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) 
        std::cin >> a[i];

    std::sort(std::begin(a), std::end(a));
    i64 ans = 0;

    for (int i = 1; i < n; i++)
        suff[a[i]]++;
    pref[a[0]]++;

    auto factor = [&](int x)
    {
        std::vector<int> f;
        for (int i = 2; 1LL * i * i <= x; i++)
        {
            if (x % i == 0)
            {
                f.emplace_back(i);

                if (i != x / i)
                    f.emplace_back(x / i);
            }
        }

        if (x != 1)
            f.emplace_back(x);

        return f;
    };

    for (int i = 1; i < n - 1; i++)
    {
        auto f = factor(a[i]);
        suff[a[i]]--;

        for (auto b : f)
        {
            if (1LL * a[i] * b < N)
                ans += pref[a[i] / b] * suff[1LL * a[i] * b];
        }

        pref[a[i]]++;
    }

    std::map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        pref[a[i]] = suff[a[i]] = 0;
        m[a[i]]++;
    }

    for (auto [num, f] : m)
        ans += 1LL * f * (f - 1) * (f - 2);

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