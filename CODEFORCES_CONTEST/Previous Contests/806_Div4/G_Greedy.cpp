#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

using i64 = long long;
using u64 = unsigned long long;

void solve()
{
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)  
        std::cin >> a[i];

    std::vector<i64> b(n, a[0]);
    for (int i = 1; i < n; ++i)
        b[i] = b[i - 1] + a[i];

    i64 ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (u64(1e9) >> (i + 1))
            ans += (a[i] >> (i + 1));
        else
            break;
    }

    for (int i = 0; i < n; i++)
    {
        i64 cur_ans = b[i] - 1LL * (i + 1) * k;
        print(cur_ans)
        for (int j = i + 1, pos = 1; j < n; ++j, ++pos)
        {
            if (u64(1e9) >> pos)
                cur_ans += (a[j] >> pos);
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