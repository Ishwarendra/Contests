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

    std::multiset<int> a, b;
    for (int i = 0; i < 2 * n; ++i)  
    {
        int x;
        std::cin >> x;

        while (x % 2 == 0)
            x /= 2;
        (i < n ? a : b).emplace(x);
    }


    for (int i = 0; i < n; i++)
    {
        int cur = *b.begin();
        int temp = cur;
        b.erase(b.begin());

        auto in_a = a.find(cur);

        if (in_a != a.end())
        {
            a.erase(in_a);
            continue;
        }

        bool done = false;
        // start finding after changing
        while (cur > 0)
        {
            cur >>= 1;
            in_a = a.find(cur);

            if (in_a != a.end())
            {
                a.erase(in_a);
                done = true;
                break;
            }
        }

        if (!done)
        {
            std::cout << "NO\n";
            return;
        }
    }

    std::cout << "YES\n";
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