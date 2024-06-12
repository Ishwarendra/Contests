#include <iostream>
#include <map>
#include <vector>
#include <set>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, q;
    std::cin >> n >> q;

    std::map<int, std::vector<int>> m;
    std::vector<i64> len(q);
    std::set<int> ele;
    for (int i = 0; i < q; i++)
    {
        int x;
        std::cin >> x;
        m[x].emplace_back(i);

        if (ele.count(x))
            ele.erase(x);
        else
            ele.emplace(x);

        len[i] = std::size(ele);
        if (i > 0)
            len[i] += len[i - 1];
    }

    auto get = [&](int l, int r)
    {
        if (r < l)
            return 0LL;
        return len[r] - (l ? len[l - 1] : 0);
    };

    std::vector<i64> a(n);
    for (auto &[num, p] : m)
    {
        p.emplace_back(q);
        for (int i = 0; i + 1 < std::size(p); i += 2)
            a[num - 1] += get(p[i], p[i + 1] - 1);
    }

    for (int i = 0; i < n; i++)
        std::cout << a[i] << " \n"[i == n - 1];
}
