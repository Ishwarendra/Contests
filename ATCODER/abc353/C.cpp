#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr int MOD = 1e8;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];
    
    std::sort(std::begin(a), std::end(a));
    std::vector<i64> p1(n);
    p1[0] = a[0];
    
    for (int i = 1; i < n; i++)
        p1[i] = p1[i - 1] + a[i];
    
    auto get = [&](auto &p, int l, int r) -> i64
    {
        if (l > r)
            return 0LL;
        return p[r] - (l ? p[l - 1] : 0);
    };
    
    i64 ans = 0;
    for (int i = 0; i < n; i++)
    {
        int j = i;
        int left = 0, right = i - 1;
        
        while (left <= right)
        {
            int mid = std::midpoint(left, right);
            if (a[mid] + a[i] >= MOD)
                j = mid, right = mid - 1;
            else
                left = mid + 1;
        }

        ans += get(p1, 0, i - 1) + 1LL * i * a[i];
        if (j < i)
            ans -= 1LL * (i - j) * MOD;
    }
    
    std::cout << ans;
    
    return 0;
}