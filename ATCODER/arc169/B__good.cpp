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
    i64 s;
    std::cin >> n >> s;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    i64 ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            i64 sum = 0;
            for (int k = i; k <= j; k++)
            {
                if (sum + a[k] > s)
                    sum = 0, ans++;
                sum += a[k];
            }

            if (sum != 0)
                ans++;
        }   
    }

    std::cout << ans << "\n";
    
    return 0;
}