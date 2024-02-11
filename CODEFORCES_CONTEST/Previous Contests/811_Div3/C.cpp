#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int s;
    std::cin >> s;

    std::string ans;
    int sum = 0;
    std::vector<int> vis(10);

    while (s)
    {
        for (int i = 9; i > 0; i--)    
        {
            if (s >= i and !vis[i])
            {
                ans += std::to_string(i)[0];
                s -= i;
                vis[i] = 1;
            }
        }
    }  

    std::reverse(std::begin(ans), std::end(ans));
    std::cout << ans << "\n";
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