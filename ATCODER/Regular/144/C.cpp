#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, k;
    std::cin >> n >> k;

    if (n < 2 * k)
    {
        std::cout << "-1\n";
        return 0;
    }

    std::vector<int> a(n + 1);
    std::set<int> not_used;

    for (int i = 1; i <= n; ++i)
        not_used.emplace(i);

    for (int i = 1; i <= n; ++i)
    {
        if (not_used.count(i + k) and i + k > n - k)
        {
            a[i] = i + k;
            not_used.erase(i + k);
        }
        else
        {
            int min = 1e6;

            auto it = not_used.lower_bound(i + k);
            if (it != std::end(not_used))
                min = std::min(*it, min);

            if (i - k >= 1)
            {
                it = not_used.lower_bound(1);
                if (*it <= (i - k))
                    min = std::min(min, *it);
            }

            if (min == 1e6)
            {
                std::cout << "-1\n";
                return 0;
            }

            a[i] = min;
            not_used.erase(min);
        }
    }

    for (int i = 1; i <= n; ++i)
        std::cout << a[i] << " ";

    return 0;
}