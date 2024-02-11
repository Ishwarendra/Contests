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

    std::vector<int> a(n), d(n);
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];
    for (int i = 0; i < n; i++)
        std::cin >> d[i];

    std::set<int> id, id_itr, dead;
    for (int i = 0; i < n; i++)
        id.emplace(i);

    auto damage = [&](int i)
    {
        auto it = id.lower_bound(i);
        i64 ans = 0;
        if (it != std::begin(id))
        {
            it = std::prev(it);
            ans += a[*it];
        }

        it = id.upper_bound(i);
        if (it != std::end(id))
            ans += a[*it];

        return ans;
    };

    for (int i = 0; i < n; i++)
    {
        if (damage(i) > d[i])
            id_itr.emplace(i);
    }

    std::vector<int> ans(n);
    for (int r = 0; r < n; r++)
    {
        int cnt = 0;
        std::vector<int> del;
        for (auto i : id_itr)
        {
            if (damage(i) > d[i])
            {
                cnt++;
                del.emplace_back(i);
            }
        }

        for (auto i : del)
        {
            dead.emplace(i);
            id.erase(i);
            id_itr.erase(i);
        }

        for (auto i : del)
        {
            auto prv = id.lower_bound(i);
            if (prv != std::begin(id) and !dead.count(*--prv))
            {
                if (damage(*prv) > d[*prv])
                    id_itr.emplace(*prv);
            }

            auto nxt = id.upper_bound(i);
            if (nxt != std::end(id) and !dead.count(*nxt))
            {
                if (damage(*nxt) > d[*nxt])
                    id_itr.emplace(*nxt);
            }
        }

        ans[r] = cnt;
        if (cnt == 0)
            break;
    }

    for (int i = 0; i < n; i++)
        std::cout << ans[i] << " \n"[i == n - 1];
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