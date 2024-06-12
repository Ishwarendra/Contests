#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    
    std::vector pw(10, 1);
    for (int i = 1; i < 10; i++)
        pw[i] = pw[i - 1] * 3;
    
    auto get = [&](auto &&self, int n) -> std::vector<std::vector<char>>
    {
        std::vector res(1, std::vector(1, '#'));
        if (n == 0)
            return res;
        
        res = self(self, n - 1);
        std::vector ans(pw[n], std::vector<char>(pw[n], '.'));
        
        auto between = [&](int x, int l, int r)
        {
            return l <= x and x < r;
        };
        
        for (int i = 0; i < pw[n]; i++)
        {
            for (int j = 0; j < pw[n]; j++)
            {
                if (between(i, pw[n - 1], pw[n - 1] * 2) and between(j, pw[n - 1], pw[n - 1] * 2))
                    continue;
                
                ans[i][j] = res[i % pw[n - 1]][j % pw[n - 1]];
            }
        }
        
        return ans;
    };
    
    auto ans = get(get, n);
    for (int i = 0; i < pw[n]; i++)
    {
        for (int j = 0; j < pw[n]; j++)
            std::cout << ans[i][j];
        std::cout << "\n";
    }
    
    return 0;
}