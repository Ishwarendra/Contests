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
    
    int n;
    std::cin >> n;

    std::map<int, std::vector<int>> num;
    std::vector<std::vector<std::pair<int, int>>> a(n);

    for (int i = 0; i < n; ++i)
    {
        int m;
        std::cin >> m;

        for (int j = 0; j < m; ++j)
        {
            int p, e;
            std::cin >> p >> e;

            a[i].emplace_back(p, e);

            num[p].push_back(e);
        }
    }

    for (auto &[_, p] : num)
    {
        std::sort(std::begin(p), std::end(p), std::greater());
        p.resize(2);
    }

    int ans = 0, lonely = 0;
    for (int i = 0; i < n; i++)
    {
        int can = 0;
        for (auto &[p, e] : a[i])
        {
            if (e == num[p][0] and num[p][1] != num[p][0])
                can = 1;
        }

        ans += can;
        lonely |= !can;
    }

    std::cout << ans + lonely;
    return 0;
}