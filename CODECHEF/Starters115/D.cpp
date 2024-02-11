#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

template <typename T>
struct Fenwick
{
    int n;
    std::vector<T> a;

    Fenwick(int n_ = 0) { init(n_); }
    template <class G>
    Fenwick(const std::vector<G> in) : Fenwick(std::size(in))
    {
        for (int i = 1; i <= n; i++)
        {
            a[i - 1] += in[i - 1];
            if (i + (i & -i) <= n)
                a[i - 1 + (i & -i)] += a[i - 1];
        }
    }

    void init(int n_)
    {
        n = n_;
        a.assign(n, T{});
    }


    void add(int x, T v)
    {
        for (int i = x + 1; i <= n; i += i & -i)
            a[i - 1] = a[i - 1] + v;
    }

    T sum(int x)
    {
        T ans{};
        for (int i = x + 1; i > 0; i -= i & -i)
            ans = ans + a[i - 1];
        return ans;
    }

    T rangeSum(int l, int r)
    {
        if (l > r)
            return T(0);
        return sum(r) - sum(l - 1);
    }
};

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    std::map<int, std::vector<int>> pos;

    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        pos[a[i]].emplace_back(i);
    }

    i64 sub = 0;
    i64 ans = n;
    i64 cur = 0;
    int last = n - 1;
    Fenwick<int> ft(n);

    for (int num = 1; num <= n; num++)
    {
        if (!pos.count(num))
            continue;

        auto p = pos[num];
        if (p[0] > last)
            continue;

        cur += num - sub;
        sub = num;
        for (int id : p)
            ft.add(id, 1);

        cur += last - p[0] + 1 - ft.rangeSum(p[0], last);
        ans = std::min(ans, cur + p[0]);
        last = p[0] - 1;
    }

    std::cout << ans << "\n";
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