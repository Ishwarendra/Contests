#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr int inf = 1e9;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, q;
    std::cin >> n >> q;

    std::string s;
    std::cin >> s;

    n = std::size(s);

    std::set<int> open, closed, co;
    if (n % 2)
    {
        for (int i = 0; i < q; i++)
        {
            int pos;
            std::cin >> pos;
            std::cout << "NO\n";
        }

        return 0;
    }

    for (int i = 0; i < n; i += 2)
    {
        if (s.substr(i, 2) == "((")
            open.emplace(i);
        else if (s.substr(i, 2) == "))")
            closed.emplace(i);
        else if (s.substr(i, 2) == ")(")
            co.emplace(i);
    }

    while (q--)
    {
        int pos;
        std::cin >> pos;
        pos--;
        s[pos] ^= '(' ^ ')';

        pos -= pos % 2;

        open.erase(pos);
        closed.erase(pos);
        co.erase(pos);

        if (s.substr(pos, 2) == "((")
            open.emplace(pos);
        else if (s.substr(pos, 2) == "))")
            closed.emplace(pos);
        else if (s.substr(pos, 2) == ")(")
            co.emplace(pos);

        std::array<int, 3> min {inf, inf, inf}, max { -inf, -inf, -inf};
        if (!open.empty())
        {
            min[0] = std::min(min[0], *std::begin(open));
            max[0] = std::max(max[0], *std::prev(std::end(open)));
        }

        if (!closed.empty())
        {
            min[1] = std::min(min[1], *std::begin(closed));
            max[1] = std::max(max[1], *std::prev(std::end(closed)));
        }

        if (!co.empty())
        {
            min[2] = std::min(min[2], *std::begin(co));
            max[2] = std::max(max[2], *std::prev(std::end(co)));
        }

        std::string ans = "YES\n";
        if (min[0] >= std::min(min[1], min[2]) or max[1] <= std::max(max[0], max[2]))
            ans = "NO\n";

        if (open.empty() and closed.empty() and co.empty())
            ans = "YES\n";

        std::cout << ans;
        // print(s, open, closed, co)
    }

    return 0;
}