#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

int solve(int n)
{
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;
    if (n <= 4)
        return 2;

    int left = 1, right = n;
    int ans = -1;

    auto good = [&](int mid)
    {
        return 1LL * mid * mid / 4 >= n; 
    };

    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (good(mid))
            ans = mid, right = mid - 1;
        else
            left = mid + 1;
    }

    return ans - 2;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    print(solve(n));

    return 0;
}