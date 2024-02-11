#include <bits/stdc++.h>

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
    std::map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        m[a[i]]++;
    }

    auto good = [&](int mid)
    {
        int extra = 0;
        for (auto [num, f] : m)
        {
            if (num > mid)
                extra += f;
            else
                extra += f - 1;
        }

        int need = 1;
        int ans = 0;
        for (auto [num, f] : m)
        {
            if (num == need)
                need++, ans++;
            else if (num > need and extra >= 2)
            {
                while (extra >= 2 and num > need)
                    ans++, need++, extra -= 2;

                if (num == need)
                    ans++, need++;
            }
            else if (num > need)
            {
                if (mid == 4)
                print(num, need)
                break;
            }
        }

        ans += extra / 2;
        return ans >= mid;
    };

    int left = 0, right = 1e9, ans = 0;
    while (left <= right)
    {
        int mid = (left + right) >> 1;

        if (good(mid))
            ans = mid, left = mid + 1;
        else
            right = mid - 1;
    }

    std::cout << ans;
    
    return 0;
}