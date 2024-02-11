#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    std::vector<int> b, one;
    int st = std::find(std::begin(a), std::end(a), 1) - std::begin(a);
    int stone = 0, stend = 0;

    int cnt = 1;
    for (int i = st + 1; i < n; i++)
    {
        if (a[i] != 1)
        {
            if (cnt)
                one.emplace_back(cnt);
            cnt = 0;
        }
        else
            cnt++;
    }

    if (cnt and st != n)
        one.emplace_back(cnt);

    cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 1)
        {
            if (cnt)
                b.emplace_back(cnt);
            cnt = 0;
        }
        else if (i > 0 and std::gcd(a[i], a[i - 1]) != 1)
        {
            if (cnt)
                b.emplace_back(cnt);
            cnt = 1;
        }
        else
            cnt++;
    }

    if (cnt)
        b.emplace_back(cnt);

    int ans = 0;
    for (int i = 1; i < n; i++)
        ans += std::gcd(a[i], a[i - 1]) == 1;

    if (std::size(one) == 1 and b.empty())
    {
        std::cout << ans - k + 1 << "\n";
        return;
    }

    if (st == 0 and !one.empty())
    {
        stone = one[0];
        one.erase(std::begin(one));
    }

    int end = 0;
    for (int i = 0; i < n; i++)
        end = (a[i] == 1 ? i : end);

    if (end == n - 1 and !one.empty())
    {
        stend = one.back();
        one.pop_back();
    }

    std::sort(std::rbegin(b), std::rend(b));
    std::sort(std::begin(one), std::end(one));

    int id = 0;
    while (k and id < std::size(b))
    {
        int x = b[id];
        if (x <= 2)
            break;

        int add = std::min(k, (x - 1) / 2);
        k -= add;
        ans -= add * 2;
        id++;
    }

    id = 0;

    while (k and id < std::size(one))
    {
        int add = std::min(k, one[id]);
        ans -= add;
        k -= add;
        if (add == one[id])
            ans--;
        id++;
    }

    id = 0;
    while (k and id < std::size(b))
    {
        int x = b[id];
        if (x % 2 == 0)
            k--, ans--;
        id++;
    }

    if (stone != 0 and k > 0)
    {
        int add = std::min(k, stone);
        ans -= add;
        k -= add;
    }

    if (stend != 0 and k > 0)
        ans -= std::min(k, stend);

    std::cout << std::max(0, ans) << "\n";
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