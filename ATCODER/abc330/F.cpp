#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    i64 k;
    std::cin >> n >> k;

    std::vector<int> X(n), Y(n);
    for (int i = 0; i < n; i++)
        std::cin >> X[i] >> Y[i];

    std::sort(std::begin(X), std::end(X));
    std::sort(std::begin(Y), std::end(Y));

    auto good = [&](i64 mid)
    {
        int l = 0, r = n - 1;
        i64 need = 0;

        while (l < r)
        {
            need += std::max(0LL, X[r] - X[l] - mid);
            need += std::max(0LL, Y[r] - Y[l] - mid);
            l++, r--;
        }

        return need <= k;
    };

    i64 left = 0, right = 1e9;
    i64 ans = 0;

    while (left <= right)
    {
        auto mid = std::midpoint(left, right);
        if (good(mid))
            ans = mid, right = mid - 1;
        else
            left = mid + 1;
    }

    std::cout << ans;
    
    return 0;
}