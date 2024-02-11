#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr int M = 350;

void solve()
{
    int n, q;
    std::cin >> n >> q;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    std::vector pref(M, std::vector(n, 0LL));
    auto pref2 = pref;

    for (int d = 1; d < M; d++)
    {
        for (int i = 0; i < d; i++)
        {
            i64 cnt = 1;
            for (int j = i; j < n; j += d)
            {
                if (j - d >= 0)
                {
                    pref[d][j] = pref[d][j - d];
                    pref2[d][j] = pref2[d][j - d];
                }

                pref[d][j] += a[j] * cnt;
                pref2[d][j] += a[j];
                cnt++;
            }
        }
    }

    while (q--)
    {
        int s, d, k;
        std::cin >> s >> d >> k;
        s--;

        if (d < M)
        {
            i64 ans = pref[d][s + d * (k - 1)];
            if (s - d >= 0)
                ans -= pref[d][s - d];

            i64 f = s / d;
            ans -= pref2[d][s + d * (k - 1)] * f;
            if (s - d >= 0)
                ans += pref2[d][s - d] * f;

            std::cout << ans << " ";
        }
        else
        {
            i64 ans = 0;
            for (int i = s, cnt = 0; cnt < k; i += d, cnt++)
                ans += 1LL * a[i] * (cnt + 1);

            std::cout << ans << " ";
        }
    }

    std::cout << "\n";
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