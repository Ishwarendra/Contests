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

    const int sz = n * (n - 1) / 2;
    std::map<int, int> m;
    for (int i = 0; i < sz; i++)  
    {
        int b;
        std::cin >> b;
        m[b]++;
    }

    int cur = n - 1;
    int sum = cur;
    for (auto &[num, f] : m)
    {
        while (f > 0)
        {
            int min = std::min(sum, f);
            sum -= min, f -= min;

            if (sum == 0)
            {
                std::cout << num << " ";
                sum = --cur;
            }
        }
    }

    std::cout << std::prev(std::end(m))->first << "\n";
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