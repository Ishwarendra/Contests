#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)  
        std::cin >> a[i];

    std::sort(std::begin(a), std::end(a));

    if (a[0] == a.back())
    {
        std::cout << "0\n";
        return;
    }

    auto good = [&](int mid)
    {
        i64 have = 0;
        for (int i = n - 1; i >= n - mid; i--)
            have += a[i];

        i64 need = 0;
        for (int i = 0; i < n - mid; i++)
            need += a[n - mid - 1] - a[i];

        return have >= need;
    };

    int left = 1, right = n, ans = 0;

    while (left <= right)
    {
        int mid = (left + right) >> 1;

        if (good(mid))
            ans = mid, right = mid - 1;
        else
            left = mid + 1;
    }

    std::cout << ans << "\n";
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