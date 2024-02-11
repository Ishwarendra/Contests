#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

std::vector<i64> dp {1, 1};

bool f(i64 sx, i64 sy, int n, i64 x, i64 y)
{
    // print(sx, sy, x, y)
    x -= sx - 1, y -= sy - 1;
    sx = sy = 1;
    // print(sx, sy, x, y)
    if (n == 1)
        return true;
    if (n == 2)
    {
        std::vector<i64> a {1, 2, 1, 2};
        std::vector<i64> b {1, 1, 3, 3};

        for (int i = 0; i < 4; i++)
        {
            if (x == a[i] and y == b[i])
                return true;
        }

        return false;
    }

    if (y > dp[n])
    {
        bool ans = f(sy + dp[n], sx, n - 1, y, x);
        return ans;
    }

    if (y <= dp[n - 1])
    {
        bool ans = f(sy, sx, n - 1, y, x);
        return ans;
    }

    return false;
}

void solve()
{
    int n;
    i64 x, y;
    std::cin >> n >> x >> y;    

    if (f(1, 1, n, x, y))
        std::cout << "YES\n";
    else
        std::cout << "NO\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    while (std::size(dp) <= 50)
        dp.push_back(dp.back() + dp[std::ssize(dp) - 2]);

    int t = 1;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}