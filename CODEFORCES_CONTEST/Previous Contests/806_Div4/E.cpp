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

    std::vector<std::vector<int>>  a(n, std::vector<int>(n));
    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < n; ++j)
        {
            char ch;
            std::cin >> ch;

            a[i][j] = ch - '0';
        }
    }

    long long ans = 0;
    std::function<void(int, int, int, int)> f;
    f = [&](int i1, int j1, int i2, int j2) 
    {
        if (i1 > i2 or j1 > j2)
            return;

        std::vector<std::vector<int>> nums(4);

        for (int j = j1; j <= j2; j++)
            nums[0].push_back(a[i1][j]);

        for (int i = i1; i <= i2; i++)
            nums[1].push_back(a[i][j2]);

        for (int j = j2; j >= j1; j--)
            nums[2].push_back(a[i2][j]);

        for (int i = i2; i >= i1; i--)
            nums[3].push_back(a[i][j1]);

        for (int i = 0; i + 1 < std::size(nums[1]); i++)
        {
            int one = 0;
            for (int j = 0; j < 4; j++)
                one += nums[j][i] == 1;

            ans += std::min(one, 4 - one);
        }

        f(i1 + 1, j1 + 1, i2 - 1, j2 - 1);
    };

    f(0, 0, n - 1, n - 1);
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