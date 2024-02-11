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

    auto check = [&](int id, int mid)
    {
        if (id - mid + 1 < 0 or id + mid - 1 >= n)
            return false;

        int need = 1;
        for (int i = id - mid + 1; i <= id; i++)
        {
            if (a[i] < need)            
                return false;
            need++;
        }

        need = mid;
        for (int i = id; i < id + mid; i++)
        {
            if (a[i] < need)
                return false;
            need--;
        }

        return true;
    };

    int ans = 1;
    for (int u = 1; u <= n; u++)
    {
        for (int i = 0; i < n; i++)
        {
            if (check(i, u))
                ans = std::max(ans, u);
        }
    }

    std::cout << ans;
    
    return 0;
}