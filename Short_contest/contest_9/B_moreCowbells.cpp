#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, k;
    std::cin >> n >> k;

    std::vector<int> s(n);
    for (int i = 0; i < n; ++i)
        std::cin >> s[i];

    int left = 1, right = 2e6;
    int ans = -1;

    auto good = [&](int mid)
    {
        int need = 0;
        int i = 0, j = n - 1;
        while (i <= j)
        {
            if (i == j)
            {
                if (s[i] > mid)
                    return false;
                
                need++, i++;
            }
            else if (s[i] + s[j] <= mid)
                i++, j--, need++;
            else
            {
                if (s[j] > mid)
                    return false;

                j--, need++;
            }
        }

        return need <= k;
    }; 

    while (left <= right)
    {
        int mid = (left + right) >> 1;
        if (good(mid))
            right = mid - 1, ans = mid;
        else
            left = mid + 1;
    }

    std::cout << ans << "\n";
    
    return 0;
}