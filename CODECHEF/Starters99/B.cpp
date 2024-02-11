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
    {
        std::cin >> a[i];
        a[i] %= 3;
    }

    auto get = [&](int x, int y, int z)
    {
        std::array<int, 3> c {x, y, z};
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int need = (c[i % 3] - a[i]) % 3;
            need = (need + 3) % 3;
            ans += need;
        }

        return ans;
    };

    int ans = 1e9;
    for (int x = 0; x < 3; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                if ((x + y + z) % 3 == 0)
                {
                    ans = std::min(ans, get(x, y, z));
                    if (ans == 2)
                    print(x, y, z)
                }
            }
        }
    }

    std::cout << ans << "\n";
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