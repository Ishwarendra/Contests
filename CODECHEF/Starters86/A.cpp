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

    int ans = 1e9;
    for (int i = 0; i < n; i++)  
    {
        int cur_ans = 0;
        for (int j : {i - 1, i + 1})
        {
            if (j < 0 or j >= n)
                continue;

            cur_ans = std::max(cur_ans, std::abs(a[i] - a[j]));
        }

        ans = std::min(ans, cur_ans);
    }

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