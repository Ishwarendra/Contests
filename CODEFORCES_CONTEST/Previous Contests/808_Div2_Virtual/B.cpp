#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

void solve()
{
    int n, l, r;
    std::cin >> n >> l >> r;

    std::vector<int> a(n);
    // a[0] = l;
    for (int i = 0; i < n; ++i)  
    {
        int rem = l % (i + 1);
        if (rem == 0)
            a[i] = l;
        else
            a[i] = (l + i + 1 - rem);
    }

    for (int i = 0; i < n; ++i)
    {
        if (a[i] > r)
        {
            std::cout << "NO\n";
            return;
        }
    }

    std::cout << "YES\n";
    // std::vector<int> g(n);
    // for (int i = 0; i < n; ++i)
    //     g[i] = std::gcd(i + 1, a[i]);
    // print(g)
    for (int i = 0; i < n; ++i)
        std::cout << a[i] << " ";
    std::cout << "\n";
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