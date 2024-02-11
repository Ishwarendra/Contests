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
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)  
        std::cin >> a[i];

    std::vector<std::vector<int>> ans(n);
    ans[0] = {a[0]};
    const int one = a[0];

    for (int i = 1; i < n; i++)
    {
        if (a[i] == one)
        {
            ans[i] = ans[i - 1];
            ans[i].emplace_back(one);
        }   
        else 
        {
            int to_find = a[i] - 1;
            int en = std::size(ans[i - 1]);
            en--;
            for (; en >= 0; en--)
            {
                if (ans[i - 1][en] == to_find)
                    break;
            }

            for (int j = 0; j < en; j++)
                ans[i].emplace_back(ans[i - 1][j]);

            ans[i].emplace_back(a[i]);
        }
    }

    auto f = [](std::vector<int> &a)
    {
        int n = std::size(a);
        for (int i = 0; i < n; i++)
            std::cout << a[i] << ".\n"[i == n - 1];
    };

    for (auto p : ans)
        f(p);
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