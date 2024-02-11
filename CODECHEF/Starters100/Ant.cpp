#include "bits/stdc++.h"


#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
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

    if (n % 2)
        std::cout << "-1\n";
    else
    {
        std::vector a(n, std::vector<int>(n));
        std::iota(std::begin(a[0]), std::end(a[0]), 0);

        std::string ans(n - 1, 'R');
        int cur = 0;
        for (int i = 1; i < n; i++)
        {
            ans += 'D';
            if (i % 2)
            {
                for (int j = n - 1; j > 0; j--)
                    a[i][j] = cur, cur = (cur + 1) % n, ans += 'L';
                ans.pop_back();
            }
            else
            {
                for (int j = 1; j < n; j++)
                    a[i][j] = cur, cur = (cur + 1) % n, ans += 'R';
                ans.pop_back();
            }
        }

        ans += 'L';
        for (int i = n - 1; i >= 0; i--)
            a[i][0] = cur, cur = (cur + 1) % n, ans += 'U';
        ans.pop_back();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                std::cout << a[i][j] << " \n"[j == n - 1];
        }

        std::cout << ans;
    }

    return 0;
}