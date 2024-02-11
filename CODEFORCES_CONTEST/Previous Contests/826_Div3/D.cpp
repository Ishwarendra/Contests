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

    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)  
        std::cin >> a[i];

    bool can = true;
    std::function<void(int, int)> f = [&](int l, int r)
    {
        if (l >= r)
            return;

        int len = r - l + 1;
        int st = (a[l] - 1) / len;
        st *= len;
        st++;

        for (int i = l; i <= r; i++)
        {
            int diff = std::abs(a[i] - st);
            if (diff >= len)
            {
                can = false;
                return;
            }                
        }

        int mid = (r + l - 1) / 2;
        f(l, mid);
        f(mid + 1, r);
    }; f(1, n);

    if (!can)
        std::cout << "-1\n";
    else
    {
        int ans = 0;
        for (int len = 2; len <= n; len *= 2)
        {
            for (int i = 1; i <= n; i += len)
            {
                if (!std::is_sorted(std::begin(a) + i, std::begin(a) + i + len))
                {
                    ans++;
                    std::sort(std::begin(a) + i, std::begin(a) + i + len);
                }
            }
        }

        std::cout << ans << "\n";
    }
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