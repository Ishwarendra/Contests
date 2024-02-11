#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

i64 sum(int n) { return 1LL * n * (n + 1) * (2 * n + 1) / 6; }
i64 sum(int x, int y) { return sum(y) - sum(x - 1); }

void solve()
{
    int n;
    std::cin >> n;

    auto getRow = [&](int x)
    {
        int l = 1, r = 2023;
        int ans = 0;

        while (l <= r)
        {
            int mid = std::midpoint(l, r);
            if (1LL * mid * (mid + 1) / 2 >= x)
                ans = mid, r = mid - 1;
            else
                l = mid + 1;
        }

        return ans;
    };  

    auto getNum = [&](int row, int pos)
    {
        i64 a = 1LL * row * (row - 1) / 2;
        a += pos;
        return a;
    };

    i64 ans = 0;
    int row = getRow(n);
    int pos = n - (row - 1) * row / 2;
    int l = pos, r = pos;

    while (row)
    {
        ans += sum(getNum(row, l), getNum(row, r));
        l = std::max(1, l - 1);
        r = std::min(r, row - 1);
        row--;
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