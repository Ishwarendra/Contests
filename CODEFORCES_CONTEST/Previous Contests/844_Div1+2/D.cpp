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

    int ans = 1;

    auto perfectSquare = [&](auto x)
    {
        i64 left = 1, right = sqrtl(x) * 2;
        int ans = 0;

        while (left <= right)
        {
            i64 mid = std::midpoint(left, right);
            if (mid * mid == x)
                return true;
            else if (mid * mid < x)
                left = mid + 1;
            else
                right = mid - 1;
        }

        return false;
    };

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int d = a[j] - a[i];

            for (int p = 1; p * p <= d; p++)
            {
                if (d % p != 0)
                    continue;

                if (p % 2 != (d / p) % 2)
                    continue;

                int q = d / p;
                // print(p, q, a[i], a[j])
                i64 ps2 = 1LL * (p + q) * (p + q) / 4;
                i64 x = ps2 - a[j];
                if (x < 0)
                    continue;

                int cur_ans = 0;
                for (int k = 0; k < n; k++)
                    cur_ans += perfectSquare(a[k] + x);

                ans = std::max(ans, cur_ans);
            }
        }
    }

    std::cout << ans << '\n';
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