#include<bits/stdc++.h>

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

    std::vector<std::pair<int, int>> a(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i].first >> a[i].second;

    std::sort(a.begin(), a.end());

    std::vector<std::pair<int, int>> ans;
    int l = -1, r = -1;

    for (int i = 0; i < n; ++i)
    {
        auto [cur_l, cur_r] = a[i];

        if (l == -1 and r == -1)
            l = cur_l, r = cur_r;

        if (cur_r <= r)
            continue;
        else if (cur_r >= r and cur_l <= r)
            r = cur_r;
        else if (cur_l > r)
            ans.emplace_back(l, r), l = cur_l, r = cur_r;
    }

    if (l != -1)
        ans.emplace_back(l, r);

    for (auto [x, y] : ans)
        std::cout << x << " " << y << "\n";

    return 0;
}