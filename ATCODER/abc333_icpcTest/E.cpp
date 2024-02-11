#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int q;
    std::cin >> q;

    std::set<std::pair<int, int>> s;
    std::vector<std::pair<int, int>> qry(q);
    int ans = 0, cnt = 0;

    std::vector<int> take(q, -1);

    for (int i = 0; i < q; i++)
    {
        int t, x;
        std::cin >> t >> x;
        qry.emplace_back(t, x);

        if (ans == -1)
            continue;

        if (t == 1)
            s.emplace(x, i), cnt++;
        else
        {
            auto it = s.upper_bound({x, q});
            if (it == std::begin(s) or (--it)->first != x)
                ans = -1;
            else
            {
                take[it->second] = 1;
                s.erase(it);
            }
        }
    }

    if (ans == -1)
    {
        std::cout << "-1\n";
        return 0;
    }

    for (auto [x, id] : s)
        take[id] = 0;

    ans = 0; 
    int sum = 0;
    for (int i = 0; i < q; i++)
    {
        sum += take[i];
        ans = std::max(ans, sum);
    }

    std::cout << ans << '\n';

    for (int i = 0; i < q; i++)
    {
        if (take[i] != -1)
            std::cout << take[i] << " ";
    }

}