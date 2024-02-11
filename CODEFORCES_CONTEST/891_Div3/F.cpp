#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

int sqrt(i64 x)
{
    int left = 1, right = std::sqrt(x) + 10;
    int ans = 0;

    while (left <= right)
    {
        int mid = std::midpoint(left, right);
        if (1LL * mid * mid <= x)
            ans = mid, left = mid + 1;
        else
            right = mid - 1;
    }

    return ans;
}

void solve()
{
    int n;
    std::cin >> n;

    std::map<int, int> m;
    for (int i = 0; i < n; i++)  
    {
        int a;
        std::cin >> a;
        m[a]++;
    }

    int q;
    std::cin >> q;

    while (q--)
    {
        int x;
        i64 y;
        std::cin >> x >> y;

        i64 D2 = 1LL * x * x - 4LL * y;
        if (D2 < 0)
        {
            std::cout << 0 << " \n"[q == 0];
            continue;
        }

        int D = sqrt(D2);
        if (1LL * D * D != D2)
        {
            std::cout << 0 << " \n"[q == 0];
            continue;
        }

        std::array<i64, 2> r{};
        r[0] = (x + D) / 2, r[1] = (x - D) / 2;

        if ((x + D) % 2)
        {
            std::cout << 0 << " \n"[q == 0];
            continue;
        }

        i64 ans = 0;
        if (r[0] == r[1])
        {
            if (m.contains(r[0]))
                ans = m[r[0]] * (m[r[0]] - 1LL) / 2;
        }
        else
        {
            if (m.contains(r[0]) and m.contains(r[1]))
                ans = 1LL * m[r[0]] * m[r[1]];
        }

        std::cout << ans << " \n"[q == 0];
    }
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