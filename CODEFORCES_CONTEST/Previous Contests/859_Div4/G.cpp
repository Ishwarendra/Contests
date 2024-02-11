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

    std::vector<int> c(n);
    for (int i = 0; i < n; i++)
        std::cin >> c[i];

    std::sort(std::begin(c), std::end(c));

    if (c.front() != 1)
    {
        std::cout << "NO\n";
        return;
    }

    i64 possible_sum = 1;
    for (int i = 1; i < n; i++)
    {
        if (c[i] > possible_sum)
        {
            std::cout << "NO\n";
            return;
        }

        possible_sum += c[i];
    }

    std::cout << "YES\n";
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