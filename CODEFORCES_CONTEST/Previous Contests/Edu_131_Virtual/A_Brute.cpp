#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

void solve()
{
    std::vector<std::vector<int>> a(2, std::vector<int>(2));
    for (int i = 0; i < 2; ++i)  
        for (int j = 0; j < 2; ++j)
            std::cin >> a[i][j];

    int ans = 2;
    for (int x : {0, 1})
    {
        for (int y : {0, 1})
        {
            auto b = a;

            int cur_ans = 0;
            bool grass = false;
            for (int i = 0; i < 2; i++)
                grass |= b[x][i], b[x][i] = 0;

            for (int i = 0; i < 2; ++i)
                grass |= b[i][y], b[i][y] = 0;
            
            cur_ans += grass;
            
            int sum = 0;
            for (int i = 0; i < 2; ++i)
                sum += b[i][0] + b[i][1];

            if (sum == 0)
                ans = std::min(ans, cur_ans);

            b = a;
        }
    }
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