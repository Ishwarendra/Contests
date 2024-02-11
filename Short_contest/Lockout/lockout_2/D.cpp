#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, p, k;
    std::cin >> n >> p >> k;

    std::vector<int> a(n);
    std::vector<i64> adj[k], pref(n);

    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    std::sort(std::begin(a), std::end(a));
    int ans = 0;
    i64 spent = 0, upto_now = 0;

    for (int i = k - 1; i < n; i += k)
    {
        if (spent + a[i] <= p)
            spent += a[i], ans += k;
        else
            break;
    }

    for (int i = 0; i < k; i++)
    {
        upto_now += a[i];
        if (upto_now > p)
            break;

        spent = upto_now;
        int cur_ans = i + 1;
        for (int j = i + k; j < n; j += k)
        {
            if (spent + a[j] <= p)
                spent += a[j], cur_ans += k;
            else
                break;
        }
        
        ans = std::max(ans, cur_ans);
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