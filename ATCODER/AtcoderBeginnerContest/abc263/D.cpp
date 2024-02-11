#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, l, r;
    std::cin >> n >> l >> r;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];

    i64 sum = std::accumulate(std::begin(a), std::end(a), 0LL);

    std::vector<i64> pref(n), suff(n), diff_l(n), diff_r(n);

    pref[0] = a[0];
    for (int i = 1; i < n; i++)
        pref[i] += pref[i - 1] + a[i];

    for (int i = 0; i < n; i++)
    {
        diff_l[i] = std::max({(i - 1 >= 0 ? diff_l[i - 1] : 0LL), 
                                pref[i] - 1LL * l * (i + 1)});
    }

    suff.back() = a.back();
    for (int i = n - 2; i >= 0; i--)
        suff[i] += suff[i + 1] + a[i];

    for (int i = n - 1; i >= 0; i--)
    {
        diff_r[i] = std::max((i + 1 < n ? diff_r[i + 1] : 0LL),
                            suff[i] - 1LL * r * (n - i));
    }

    i64 max = 0;
    for (int i = 0; i < n - 1; i++)
        max = std::max(max, diff_l[i] + diff_r[i + 1]);

    std::cout << std::min({sum - max, 1LL * l * n, 1LL * r * n}) << "\n";
    
    return 0;
}