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

    std::map<int, int> a;
    for (int i = 0; i < n; i++)
    {
        int x;
        std::cin >> x;
        a[x]++;
    }

    std::vector<int> cnt(n + 1);
    for (auto [x, f] : a)
    {
        for (int j = 0; j <= n; j += x)
            cnt[j] += f;
    }

    int max_id = std::max_element(std::begin(cnt) + 1, std::end(cnt)) - std::begin(cnt);
    std::cout << cnt[max_id] << "\n";
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