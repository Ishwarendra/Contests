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

    std::set<int, std::greater<int>> nums;
    int i = 0, j = n - 1;
    while (i < j)
    {
        if (!nums.empty() and std::size(nums) == *std::begin(nums))
            break;

        if (a[i] < a[j])
            nums.emplace(a[i++]);
        else
            nums.emplace(a[j--]);
    }

    int max = *std::begin(nums);
    std::cout << n - max << "\n";
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