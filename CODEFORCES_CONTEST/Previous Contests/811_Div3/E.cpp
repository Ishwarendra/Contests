#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

using i64 = long long;

std::vector<std::set<int>> ops(100);

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)  
    {
        std::cin >> a[i];

        if (a[i] & 1)
            a[i] += a[i] % 10;
    }

    std::sort(std::begin(a), std::end(a), [&](int x, int y)
    {
        return x % 10 < y % 10;
    });

    for (int i = 0; i < n - 1; ++i)
    {
        auto s1 = ops[a[i] % 100];
        auto s2 = ops[a[i + 1] % 100];

        bool can = false;
        for (int j : s1)
        {
            if (s2.count(j))
            {
                can = true;
                break;
            }
        }

        if (!can or (a[i] % 10 == 0 and a[i] != a[i + 1]))
        {
            std::cout << "No\n";
            return;
        }
    }

    std::cout << "Yes\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    for (int i = 0; i < 100; i++)
    {
        std::set<int> s;
        int cur = i;
        while (!s.count(cur))
        {
            s.emplace(cur);
            if (cur >= i)
                ops[i].emplace(cur);

            cur = (cur + (cur % 10)) % 100;
        }
    }
   
    int t = 1;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}