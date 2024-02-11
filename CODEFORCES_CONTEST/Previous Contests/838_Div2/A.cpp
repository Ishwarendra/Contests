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
    std::set<int> even, odd;
    even.emplace(1e9), odd.emplace(1e9);

    for (int i = 0; i < n; i++)  
    {
        int x;
        std::cin >> x;
        a[i] = x;

        int count = 0;
        if (a[i] % 2)
        {
            while (x % 2 != 0)
                x /= 2, count++;
            odd.emplace(count);
        }
        else
        {
            while (x % 2 == 0)
                x /= 2, count++;
            even.emplace(count);
        }
    }
    int sum = std::accumulate(std::begin(a), std::end(a), 0);
    if (sum % 2)
        std::cout << std::min(*std::begin(odd), *std::begin(even)) << "\n";
    else
        std::cout << "0\n";
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