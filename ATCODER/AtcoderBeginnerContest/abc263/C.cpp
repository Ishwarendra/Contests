#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h>
#else
#define trace(...) 1;
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> ans;

    std::function<void(int, int, std::vector<int> &)> f;

    f = [&](int i, int cur, std::vector<int> &temp)
    {
        if (i == n)
        {
            ans.push_back(temp);
            return;
        }

        if (cur > m)
            return;

        f(i, cur + 1, temp);
        temp.push_back(cur);
        f(i + 1, cur + 1, temp);
        temp.pop_back();
    };

    std::vector<int> a;
    f(0, 1, a);

    std::sort(std::begin(ans), std::end(ans));
    for (auto p : ans)
    {
        for (auto j : p)
            std::cout << j << " ";
        std::cout << "\n";
    }

    return 0;
}