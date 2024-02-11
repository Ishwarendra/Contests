#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, k;
    std::cin >> n >> k;

    if (n == 2)
    {
        std::cout << (k == 1 ? "2 1\n" : "1 2\n");
        return;
    }

    k--;
    std::vector<int> ans(1, 1);
    for (int i = 1; i < n; i++)
    {
        if (k)
        {
            ans.emplace_back(ans.back() + 1);
            k--;
        }
        else
        {
            if (ans.empty())
                ans.emplace_back(2);

            int par = ans.back() % 2;
            int num1 = ans.back() + 2;
            int num2 = ans.back() + 1;

            while (num1 <= n)
            {
                ans.emplace_back(num1);
                num1 += 2;
            }

            while (num2 <= n)
            {
                ans.emplace_back(num2);
                num2 += 2;
            }

            break;
        }
    }

    for (int i = 0; i < n; i++)
        std::cout << ans[i] << " \n"[i == n - 1];
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}