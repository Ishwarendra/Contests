#include<bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, a, b;
    std::cin >> n >> a >> b;

    std::vector<int> A(n);
    for (int i = 0; i < n; ++i)
        std::cin >> A[i];

    int left = 1, right = 1e9;

    auto good = [&](int mid)
    {
        i64 bal = 0LL;

        for (int i = 0; i < n; ++i)
        {
            if (mid > A[i])
                bal -= (mid - A[i] + a - 1) / a;
            else
                bal += (A[i] - mid) / b;
        }

        return bal >= 0;
    };

    int ans = 0;
    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (good(mid))
            left = mid + 1, ans = mid;
        else
            right = mid - 1;
    }

    std::cout << ans << "\n";
    
    return 0;
}