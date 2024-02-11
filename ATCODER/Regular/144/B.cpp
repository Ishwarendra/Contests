#include <bits/stdc++.h>

#define int long long
#define print(x) std::cout << x << "\n";

int32_t main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, a, b;
    std::cin >> n >> a >> b;

    std::vector<int> nums(n);
    for (int i = 0; i < n; ++i)
        std::cin >> nums[i];

    auto good = [&](int mid)
    {
        std::vector<int> A = nums;
        std::sort(std::begin(A), std::end(A));

        int st = 0, en = n - 1;
        while (st < en)
        {
            if (A[st] >= mid)
                return true;
            if (A[en] < mid)
                return false;

            int fa1 = (mid - A[st] + a - 1) / a;
            int fa2 = (A[en] - mid) / b;

            int fa = std::min(fa1, fa2);
            // std::cout << mid << " " << fa << "\n";

            A[st] += fa * a;
            A[en] -= fa * b;

            if (A[en] - b < mid)
                en--;
            if (A[st] >= mid)
                st++;
        }

        return *std::min_element(std::begin(A), std::end(A)) >= mid;
    };

    int left = 1, right = 1e9 + 1;
    int ans = 1;

    while (left <= right)
    {
        int mid = (left + right) >> 1;

        if (good(mid))
            ans = mid, left = mid + 1;
        else
        {
            // print(mid)
            right = mid - 1;
        }
    }

    std::cout << ans;

    return 0;
}