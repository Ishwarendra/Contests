#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

i64 C(i64 n) { return 1LL * n * (n - 1) / 2; }

void solve()
{
    int n, b, x;
    std::cin >> n >> b >> x;

    std::vector<int> c(n);
    std::map<int, int> cnt, ff;
    i64 tot_sum = 0;
    for (int i = 0; i < n; i++)  
    {
        std::cin >> c[i];
        cnt[c[i]]++;
        tot_sum += C(c[i]);
    }

    int sum = std::accumulate(std::begin(c), std::end(c), 0);

    for (auto &[m, f] : cnt)
        ff[f]++;

    i64 ans = 0;
    for (int k = 2; k <= sum; k++)
    {
        i64 cur = 0;
        for (auto &[f, freq] : cnt)
            cur += 1LL * freq * (C((f + k - 1) / k) * (f % k) + C(f / k) * (k - (f % k)));

        cur = tot_sum - cur;
        cur *= b;
        cur -= 1LL * (k - 1) * x;
        ans = std::max(ans, cur); 
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