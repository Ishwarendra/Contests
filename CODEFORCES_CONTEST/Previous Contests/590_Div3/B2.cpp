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
    
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    std::deque<int> d;
    std::set<int> already;

    for (int i = 0; i < n; i++)
    {
        if (std::size(already) < k)
        {
            if (already.count(a[i]))
                continue;
            else
            {
                already.emplace(a[i]);
                d.push_front(a[i]);
            }
        }
        else
        {
            if (already.count(a[i]))
                continue;
            else
            {
                already.emplace(a[i]);
                already.erase(d.back());
                d.push_front(a[i]);
                d.pop_back();
            }
        }
    }

    std::cout << std::size(d) << "\n";
    while (!d.empty())
    {
        std::cout << d.front() << " ";
        d.pop_front();
    }
    
    return 0;
}