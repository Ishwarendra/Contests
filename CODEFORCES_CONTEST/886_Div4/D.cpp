#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];

    std::sort(std::begin(a), std::end(a));
    int cnt = 1;
    std::vector<int> options;

    for (int i = 1; i < n; i++)
    {
        if (a[i] - a[i - 1] > k)
            options.emplace_back(cnt), cnt = 1;
        else
            cnt++;
    }

    options.emplace_back(cnt);

    int sum = std::accumulate(std::begin(options), std::end(options), 0);
    int ans = n;

    for (int x : options)
        ans = std::min(ans, sum - x);

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