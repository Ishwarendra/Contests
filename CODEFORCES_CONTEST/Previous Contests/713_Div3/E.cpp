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
    int n, l, r;
    i64 s;
    std::cin >> n >> l >> r >> s;

    auto f = [&](int a, int x) -> i64 
    {
        return 1LL * x * (2LL * a + (x - 1)) / 2;
    };

    if (f(1, r - l + 1) > s or f(n - (r - l), r - l + 1) < s)
    {
        std::cout << "-1\n";
        return;
    }

    std::vector<int> a(n);

    for (int i = l - 1, cur = n - (r - l); i < r; i++, cur++)
        a[i] = cur;

    i64 have = std::accumulate(std::begin(a), std::end(a), 0LL);
    i64 need = s;
    print(a)
    int min = 1;
    for (int i = l - 1; i < r; i++)
    {
        if (have == need)
            break;
        else if (have > need)
        {
            if (have - need <= a[i] - min)
                a[i] -= (have - need), have = need;
            else
            {
                have -= (a[i] - min);
                a[i] = min++;
            }
        }
    }

    if (have == need)
    {
        std::set<int> used, not_used;
        for (int i = 0; i < n; ++i)
            used.emplace(a[i]);

        for (int i = 1; i <= n; i++)
        {
            if (!used.count(i))
                not_used.emplace(i);
        }

        for (int i = 0; i < n; i++)
        {
            if (a[i] == 0)
            {
                assert(not_used.size() != 0);
                a[i] = *not_used.begin(), not_used.erase(a[i]);
            }
        }

        for (int i = 0; i < n; ++i)
            std::cout << a[i] << " \n"[i == n - 1];
    }
    else
        std::cout << "-1\n";
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