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

    std::sort(std::rbegin(a), std::rend(a));
    int l = 0, r = n - 1;
    i64 sum = 0;
    int d = a.front() - a.back();

    std::vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        if (sum + a[l] < d)
        {
            sum += a[l];
            ans[i] = a[l++];
        }
        else
        {
            sum += a[r];
            ans[i] = a[r];

            if (a[r] >= 0)
            {
                std::cout << "No\n";
                return;
            }
            r--;
        }
    }

    std::cout << "Yes\n";
    for (int i = 0; i < n; i++)
        std::cout << ans[i] << " \n"[i == n - 1];
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