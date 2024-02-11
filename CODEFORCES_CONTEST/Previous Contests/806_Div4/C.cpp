#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];

    for (int i = 0; i < n; ++i)
    {
        int m;
        std::cin >> m;

        int d = 0, u = 0;
        for (int j = 0; j < m; ++j)
        {
            char ch;
            std::cin >> ch;

            (ch == 'D' ? u++ : d++);
        }

        a[i] = (a[i] + u - d + 8100) % 10;
    }

    for (int i = 0; i < n; ++i)
        std::cout << a[i] << " \n"[i == n - 1];
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