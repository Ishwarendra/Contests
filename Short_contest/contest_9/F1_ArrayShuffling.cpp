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

    if (n <= 2)
    {
        std::reverse(std::begin(a), std::end(a));
        for (int i = 0; i < n; ++i)
            std::cout << a[i] << " \n"[i == n - 1];

        return;
    }

    for (int i = 1; i <= n; i++)
        std::cout << a[(i + 1) % n] << " \n"[i == n];
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