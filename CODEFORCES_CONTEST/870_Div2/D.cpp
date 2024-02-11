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

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    std::vector<i64> pref(n), suff(n);
    pref[0] = a[0] - 1, suff.back() = a.back() - 1;

    for (int i = 1; i < n; i++)
        pref[i] = std::max<i64>(pref[i - 1], a[i]) - 1;
    for (int i = n - 2; i >= 0; i--)
        suff[i] = std::max<i64>(suff[i + 1], a[i]) - 1;

    i64 ans = 0;
    for (int i = 1; i < n - 1; i++)
        ans = std::max(ans, pref[i - 1] + suff[i + 1] + a[i]);

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