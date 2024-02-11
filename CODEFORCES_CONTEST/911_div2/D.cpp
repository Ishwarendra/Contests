#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr int N = 1e5;
std::array<i64, N + 1> m{}, cnt{};

void solve()
{
    int n;
    std::cin >> n;

    std::vector<i64> a(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        m[a[i]]++;
    }

    std::sort(std::begin(a), std::end(a));
    i64 ans = 0;
    for (int g = N; g >= 1; g--)
    {
        i64 pref = 0;
        cnt[g] = 0;
        for (int num = g; num <= N; num += g)
        {
            int uid = std::upper_bound(std::begin(a), std::end(a), num) - std::begin(a);
            cnt[g] += m[num] * (m[num] - 1) * (m[num] - 2) / 6;
            cnt[g] += m[num] * (m[num] - 1) / 2 * (pref + n - uid);
            cnt[g] += pref * (n - uid) * m[num];

            pref += m[num];
        }

        for (int num = 2 * g; num <= N; num += g)
            cnt[g] -= cnt[num];

        ans += 1LL * cnt[g] * g;
    }

    std::cout << ans << "\n";
    for (int i = 0; i < n; i++)
        m[a[i]]--;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int i64;
    std::cin >> i64;

    while (i64--)
        solve();

    return 0;
}