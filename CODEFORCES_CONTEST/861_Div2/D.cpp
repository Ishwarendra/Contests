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
    
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    std::map<int, int> m;
    int total = 0;
    for (int i = 0; i < n - k + 1; i++)
    {
        total++;
        m[a[i]]++;
    }

    i64 ans = 0;
    int left = 0, right = n - k;
    for (int i = k - 1; i >= 0; i--)
    {
        ans += total - m[a[i]];
        m[a[left]]--;
        m[a[right]]--;
        m[a[++left]]++;
        m[a[++right]]++;
        print(ans)
    }

    right = n - k;
    for (int i = k; i < n; i++)
    {
        ans += total - m[a[right]];
        m[a[right]]--;
        right--;
    }

    std::cout << ans;
    
    return 0;
}