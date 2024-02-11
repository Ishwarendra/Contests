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

    auto possible = [&](int x)
    {
        int ans = 0;
        for (int i = 0; i < n; i++)
            ans ^= (a[i] ^ x);

        return ans == 0;
    };

    for (int i = 0; i < (1 << 8); i++)
    {
        if (possible(i))
        {
            std::cout << i << "\n";
            return;
        }
    }

    std::cout << "-1\n";
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