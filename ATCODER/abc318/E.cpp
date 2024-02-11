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
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)    
        std::cin >> a[i];

    std::map<int, int> left, right;
    for (int i = 1; i < n; i++)
        right[a[i]]++;

    i64 ans = 0;
    i64 ways = 0;
    for (int i = 1; i < n; i++)
    {
        ans -= 1LL * left[a[i - 1]] * right[a[i - 1]];
        if (a[i - 1] != a[i])
            ans -= 1LL * left[a[i]] * right[a[i]];

        left[a[i - 1]]++;
        right[a[i]]--;
        ans += 1LL * left[a[i - 1]] * right[a[i - 1]];

        if (a[i - 1] != a[i])
            ans += 1LL * left[a[i]] * right[a[i]];

        ways += ans - 1LL * left[a[i]] * right[a[i]]; 
    }

    std::cout << ways;
    
    return 0;
}