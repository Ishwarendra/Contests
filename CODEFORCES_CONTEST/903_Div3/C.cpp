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

    std::vector<std::string> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    int ans = 0;
    auto work = [&]()
    {
        for (int i = 0; i < n / 2; i++) 
        {
            for (int j = i; j < n - i - 1; j++) 
            {
                std::string s;
                s += a[i][j];
                s += a[n - 1 - j][i];
                s += a[n - 1 - i][n - 1 - j]; 
                s += a[j][n - 1 - i];
                
                std::sort(std::begin(s), std::end(s));
                for (int id = 0; id < 3; id++)
                    ans += s[3] - s[id];
            }
        }
    };

    work();
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