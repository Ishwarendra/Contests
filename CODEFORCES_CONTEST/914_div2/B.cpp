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

    std::vector<std::pair<int, int>> a(n);
    for (int i = 0; i < n; i++)  
    {
        std::cin >> a[i].first;
        a[i].second = i;
    }

    std::sort(std::begin(a), std::end(a));
    std::vector<i64> p(n), ok(n);
    ok[0] = 1;
    p[0] = a[0].first;
    for (int i = 1; i < n; i++)
    {
        p[i] = p[i - 1] + a[i].first;
        if (p[i - 1] >= a[i].first)
            ok[i] = 1;
    }

    for (int i = 1; i < n; i++)
        ok[i] += ok[i - 1];

    auto get = [&](int id)
    {
        int left = id + 1, right = n - 1;
        int ans = id;
        while (left <= right)
        {
            int mid = std::midpoint(left, right);
            if (ok[mid] - ok[id] == mid - id)
                ans = mid, left = mid + 1;
            else
                right = mid - 1;
        }

        return ans;
    };

    std::vector<int> ans(n);
    for (int i = 0; auto &[x, id] : a)
    {
        ans[id] = i;
        int j = get(i);
        ans[id] += j - i;
        i++;
    }

    for (int i = 0; i < n; i++)
        std::cout << ans[i] << " \n"[i == n - 1];
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