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

    std::vector<int> b(n);
    for (int i = 0; i < n; ++i)  
        std::cin >> b[i];

    int mx = -1, mn = 1e9;

    for (int i = 0; i < n; i++)
    {
        mn = std::min(mn, b[i]);
        mx = std::max(mx, b[i]);
        
        if (b[i] != mn and b[i] != mx)
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