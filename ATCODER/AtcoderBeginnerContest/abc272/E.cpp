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

    std::multiset<std::array<int, 2>> m;
    std::multiset<std::array<int, 3>> extra;

    for (int i = 0; i < n; i++)
    {
        int x;
        std::cin >> x;
        if (0 <= x and x <= n - 1)
            extra.insert({1, x, i + 1});
        else if (x < 0)
        {
            int when = (std::abs(x) + i) / (i + 1); 
            if (when > k)
                continue;

            extra.insert({when, x, i + 1});
        }
    }

    auto mex = [&](std::multiset<std::array<int, 2>> &a)
    {
        std::multiset<std::array<int, 2>> b;
        std::set<int> can;
        while (!a.empty())
        {
            auto [x, id] = *std::begin(a);
            a.erase(std::begin(a));

            if (0 <= x and x <= n - 1)
                can.emplace(x);

            x += id;
            if (0 <= x and x <= n - 1)
                b.insert({x, id});
        }

        a = b;
        int ans = 0;

        while (can.count(ans))
            ans++;

        return ans;
    };

    for (int i = 1; i <= k; i++)
    {
        while (!extra.empty())
        {
            auto [when, x, id] = *std::begin(extra);
            if (when <= i)
            {
                extra.erase(std::begin(extra));
                if (x + 1LL * when * id <= n - 1)
                    m.insert({x + when * id, id});
            }
            else
                break;
        }
        
        std::cout << mex(m) << "\n";
    }
}