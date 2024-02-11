#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i)  
        std::cin >> a[i];

    for (int i = 0; i < n; ++i)
        std::cin >> b[i];

    int max = 0;
    for (int i = 0; i < n; ++i)
    {
        if (b[i] > a[i])
        {
            std::cout << "NO\n";
            return;
        }
        max = std::max(max, a[i] - b[i]);
    }

    for (int i = 0; i < n; i++)
        a[i] = std::max(0, a[i] - max);

    for (int i = 0; i < n; ++i)
    {
        if (a[i] != b[i])
        {
            std::cout << "NO\n";
            return;
        }
    }

    std::cout << "YES\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    
    while(t--)
        solve();
    
    return 0;
}