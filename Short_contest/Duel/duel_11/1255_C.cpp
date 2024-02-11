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

    int n;
    std::cin >> n;

    std::vector a(n - 2, std::array<int, 3> {});
    std::vector<std::pair<int, int>> pos[n];

    for (int i = 0; auto &[x, y, z] : a)
    {
        std::cin >> x >> y >> z;
        x--, y--, z--;

        std::vector<std::vector<int>> ids {{0, 1, 2}, {1, 0, 2}, {2, 0, 1}};
        for (auto id : ids)
            pos[a[i][id[0]]].emplace_back(a[i][id[1]], a[i][id[2]]);

        i++;
    }

    if (n == 3)
    {
        for (int i = 0; i < 3; i++)
            std::cout << a[0][i] + 1 << " \n"[i == n - 1];
        return 0;
    }

    std::vector<int> ans(n, -1);
    std::set<int> done;
    for (int i = 0; i < n; i++)
    {
        if (std::size(pos[i]) == 1)
        {
            ans[0] = i;
            done.emplace(ans[0]);
            break;
        }
    }
    
    auto get = [&](int prev)
    {
        for (auto [y, z] : pos[prev])
        {
            if (std::size(pos[y]) == 2)
                return y;
            else if (std::size(pos[z]) == 2)
                return z;
        }

        return -1;
    };

    ans[1] = get(ans[0]);
    done.emplace(ans[1]);

    for (int i = 1; i < n - 3; i++)
    {
        assert(ans[i] != -1);
        std::map<int, int> m;
        for (auto [y, z] : pos[ans[i]])
        {
            if (!done.count(y))            
                m[y]++;
            if (!done.count(z))
                m[z]++;
        }

        for (auto &[num, freq] : m)
        {
            if (freq == 2 and !done.count(num))
            {
                ans[i + 1] = num;
                done.emplace(ans[i + 1]);
                break;
            }
        }
    }   

    for (int i = 0; i < n; i++)
    {
        if (!done.count(i) and std::size(pos[i]) == 1)
            ans[n - 1] = i, done.emplace(i);
        if (!done.count(i) and std::size(pos[i]) == 2)
            ans[n - 2] = i, done.emplace(i);
    }

    // for (int i = 0; i < n; i++)
    // {
    //     if (std::size(pos[i]) <= 2)
    //         print(i+1, pos[i])
    // }

    for (int i = 0; i < n; i++)
        std::cout << ans[i] + 1 << " \n"[i == n - 1];

    return 0;
}