#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    std::set<int> s;
    for (int i = 0; i < 10000; i++)
        s.emplace(i + 1);

    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    while (k--)
    {
        std::vector<int> del;
        for (auto x : a)
        {
            auto it = std::begin(s);
            x--;
            while (x--)
                it++;

            del.emplace_back(*it);
        }

        for (auto x : del)
            s.erase(x);
    }

    // while (k--)
    // {
    //     // int cnt = 0;
    //     // for (int x : s)
    //     // {
    //     //     if (cnt > 4)
    //     //         break;
    //     //     std::cout << x << " ";
    //     //     cnt++;
    //     // }

    //     // std::cout << "...\n";
    //     for (int id = 1; int x : a)
    //     {
    //         auto it = std::begin(s);
    //         x -= id;
    //         while (x--)
    //             it++;
    //         s.erase(it);
    //         id++;
    //     }
    //     auto cur = std::begin(s);
    //     // print(*cur, *std::next(cur), *std::next(next(cur)))
    // }

    std::cout << (*std::begin(s)) << "\n"; 
   
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