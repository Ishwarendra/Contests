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

    int even = 1, odd = 0, prefix = 0;
    std::array<i64, 3> ans{};
    int zero_id = -1;

    for (int i = 0; i < n; i++)
    {
        int rem = i + 1;
        if (a[i] == 0)
        {
            zero_id = i, even = 1, odd = 0, prefix = 0;
            ans[2] += zero_id + 1;
            continue;
        }

        ans[2] += zero_id + 1;
        rem -= zero_id + 1;

        prefix += a[i] < 0;
        if (prefix % 2 == 0)
            ans[0] += even, rem -= even++;
        else    
            ans[0] += odd, rem -= odd++;

        // print(rem)
        ans[1] += rem;
    }

    for (int i = 0; i < 3; i++)  
        std::cout << ans[i] << " \n"[i == 2];
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