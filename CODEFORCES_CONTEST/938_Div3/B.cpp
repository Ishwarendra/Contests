#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, c, d;
    std::cin >> n >> c >> d;  

    std::vector<int> a(n * n);
    for (int i = 0; i < n * n; i++)
        std::cin >> a[i];

    std::sort(std::begin(a), std::end(a));
    std::vector<int> nums(1, a[0]);
    for (int i = 1; i < n; i++)
        nums.emplace_back(nums.back() + d);

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n; j++)
            nums.emplace_back(nums[j + i * n] + c);
    }

    std::sort(std::begin(nums), std::end(nums));
    std::cout << (nums == a ? "YES\n" : "NO\n");
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