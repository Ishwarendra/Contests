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

    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)    
        std::cin >> a[i];
    for (int i = 0; i < n; i++)
        std::cin >> b[i];

    auto check = [&]()
    {
        int k = -1;
        for (int i = 0; i < n; i++)
        {
            if (b[i] == 0 and a[i] > 0)
                return false;
            if (b[i] != 0 and a[i] % b[i])
                return false;

            if (k == -1 and b[i] != 0)
                k = a[i] / b[i];

            if (b[i] != 0 and a[i] / b[i] != k)
                return false;
        }

        return true;
    };

    for (int i = 0; i < 900; i++)
    {
        if (check())
        {
            std::cout << "YES\n";
            return;
        }

        std::vector<int> c(n);
        for (int j = 0; j < n; j++)
            c[j] = std::abs(a[j] - b[j]);

        a = b;
        b = c;
    }

    std::cout << "NO\n";
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