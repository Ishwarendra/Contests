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

    std::vector<int> a(n);  
    std::map<int, int> m;
    std::set<int> id;

    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        m[a[i]]++;
        id.emplace(i);
    }

    int turn = 1;
    while (std::size(m) > 1)
    {
        int p = -1;
        std::vector<int> del;
        for (int i : id)
        {
            if (a[i] == p)
                continue;
            else
            {
                del.emplace_back(i);
                p = a[i];
            }
        }

        for (auto x : del)
        {
            m[a[x]]--;
            if (m[a[x]] == 0)
                m.erase(a[x]);
            id.erase(x);
        }

        turn ^= 1;
    }

    for (auto [num, f] : m)
    {
        while (f--)
            turn ^= 1;
    }

    std::cout << (turn ? "Bob\n" : "Alice\n");
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