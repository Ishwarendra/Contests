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
    
    int n, t, m;
    std::cin >> n >> t >> m;

    std::vector<int> a(m), b(m);
    for (int i = 0; i < m; i++)
    {
        std::cin >> a[i] >> b[i];
        a[i]--, b[i]--;
    }

    std::vector<int> c(n, 0);
    int ans = 0;
    std::function<void(int, int)> f = [&](int u, int d)
    {
        if (u == n)
        {
            int ok = d == t;
            for (int i = 0; i < m; i++)
            {
                if (c[a[i]] == c[b[i]])
                    ok = 0;
            }

            ans += ok;
            return;
        }

        for (int i = 0; i <= d; i++)
        {
            c[u] = i;
            f(u + 1, std::max(d, i + 1));
        }
    }; f(0, 0);

    std::cout << ans;
    
    return 0;
}