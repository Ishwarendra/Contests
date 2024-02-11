#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> b(n);
    std::map<int, std::set<int>> pos;
    for (int i = 0; i < n; i++)  
    {
        std::cin >> b[i];
        pos[b[i]].emplace(i);
    }

    auto original = b;

    auto _ = std::set(std::begin(b), std::end(b));
    i64 sum = 0;
    for (auto i : _)
        sum += i;

    if (sum > n)
    {
        std::cout << "-1\n";
        return;
    }

    std::vector<int> a(n, -1);
    int cur = 1;
    for (int i = 0; i < n; i++)
    {
        auto &index = pos[b[i]];
        int change = 0;
        int max = b[i];
        while (!index.empty() and max > 0)
        {
            auto id = *std::begin(index);
            index.erase(id);
            a[id] = cur;
            b[id] = 0;
            change |= 1;      
            max--;      
        }

        cur += change;
    }

    std::map<int, int> m;
    for (int i = 0; i < n; i++)
        m[a[i]]++;

    for (int i = 0; i < n; i++)
    {
        if (original[i] != m[a[i]])
        {
            std::cout << "-1\n";
            return;
        }
    }

    for (int i = 0; i < n; i++)
        std::cout << a[i] << " \n"[i == n - 1];
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