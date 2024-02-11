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

    std::cout << "2\n";
    std::vector<int> vis(n + 1);

    for (int i = 1; i <= n; i++)    
    {
        if (!vis[i])
        {
            int j = i;
            while (j <= n)
            {
                std::cout << j << " ";
                vis[j] = 1;
                j *= 2;
            }
        }
    }

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