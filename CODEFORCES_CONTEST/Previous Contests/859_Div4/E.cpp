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

    std::vector<i64> a(n);
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];

    for (int i = 1; i < n; i++)
        a[i] += a[i - 1];

    int left = 0, right = n - 1;
    int ans = 0;

    auto query = [&](int i, int j)
    {
        assert(j >= i);
        std::cout << "? " << j - i + 1 << " ";
        for (int x = i; x <= j; x++)
            std::cout << x + 1 << " ";
        std::cout << std::endl;

        int have;
        std::cin >> have;
        return have;
    };  

    while (left < right)
    {
        int mid = std::midpoint(left, right);
        auto sum_l = a[mid] - (left == 0 ? 0 : a[left - 1]);
        int have_l = query(left, mid);
        // print(left, right, sum_l, have_l)
        if (have_l - sum_l == 1)
            ans = mid, right = mid;
        else 
            left = mid + 1, ans = mid + 1;
        // print("now", left, right)
    }

    std::cout << "! " << ans + 1 << std::endl;
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