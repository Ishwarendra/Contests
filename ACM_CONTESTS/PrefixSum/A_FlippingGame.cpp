#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        if (i)
            a[i] += a[i - 1];
    }

    // Since we have to perform exactly one move so we cannot
    // keep initial value as total number of ones initially
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            // 0 to i - 1 and j + 1 to n remains same
            int cur = (i ? a[i - 1] : 0);
            cur += a.back() - a[j];

            int window_len = j - i + 1;

            // flip i to j and `length - total ones = total zeros`
            cur += window_len - (a[j] - (i ? a[i - 1] : 0));
            ans = std::max(ans, cur);
        }
    }

    std::cout << ans;
    
    return 0;
}