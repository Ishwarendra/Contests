#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

int sum(int x)
{
    int ans = 0;
    while (x)
        ans += x % 10, x /= 10;
    return ans;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    constexpr int N = 2e5 + 1;
    std::vector<int> ans(N);

    for (int i = 1; i < N; i++)
        ans[i] = ans[i - 1] + sum(i);

    int t;
    std::cin >> t;

    while (t--)
    {
        int n;
        std::cin >> n;
        std::cout << ans[n] << "\n";
    }
    
    return 0;
}