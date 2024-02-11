#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;
using i128 = __int128;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n), one(n);
    int empty = 1;
    i128 prod = 1;

    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        if (a[i] == 1)
            one[i] = 1, empty = 0;

        if (prod <= i64(1e16))
            prod *= a[i];
    }

    int st = 0, en = n - 1;
    while (st < n and one[st])
        st++;
    while (en >= 0 and one[en])
        en--;

    if (prod > i64(1e16))
    {
        std::cout << st + 1 << " " << en + 1 << "\n";
        return;
    }

    std::vector<int> id;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != 1)
            id.emplace_back(i);
    }

    prod = 1;
    std::vector<i64> psum(n), pprod(n);
    psum[0] = a[0], pprod[0] = a[0];

    for (int i = 1; i < n; i++)
    {
        psum[i] = psum[i - 1] + a[i];
        pprod[i] = pprod[i - 1] * a[i];
    }

    auto sum = [&](int l, int r)
    {
        if (l > r)
            return 0LL;
        return psum[r] - (l ? psum[l - 1] : 0);
    };

    auto product = [&](int l, int r)
    {
        if (l > r)
            return 1LL;
        return pprod[r] / (l ? pprod[l - 1] : 1);
    };

    std::array<i64, 3> ans{psum.back(), 1, 1};
    for (int i = 0; i < std::size(id); i++)
    {
        for (int j = i; j < std::size(id); j++)
        {
            i64 sum_ = sum(0, id[i] - 1);
            sum_ += sum(id[j] + 1, n - 1);
            sum_ += product(id[i], id[j]);
            print(sum_, id[i], id[j])
            ans = std::max(ans, std::array<i64, 3> {sum_, id[i] + 1, id[j] + 1});
        }
    }

    std::cout << ans[1] << " " << ans[2] << '\n';
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