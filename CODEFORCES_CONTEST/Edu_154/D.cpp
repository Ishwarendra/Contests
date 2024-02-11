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

    auto get = [&](std::vector<int> a)
    {
        std::vector<int> s1(n), s2(n);
        for (int i = 1; i < n; i++)
            s1[i] = s1[i - 1] + (a[i - 1] <= a[i]);
        for (int i = n - 2; i >= 0; i--)
            s2[i] = s2[i + 1] + (a[i + 1] <= a[i]);

        int ans = std::min(s2[0], s1[n - 1] + 1);
        for (int i = 0; i < n - 1; i++)
            ans = std::min(s1[i] + s2[i + 1] + 1, ans);

        return ans;
    };       

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    std::cout << get(a) << "\n";
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