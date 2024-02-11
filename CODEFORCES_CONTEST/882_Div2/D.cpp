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
    const int n;
    std::vector<T> a;

    Fenwick() {}
    Fenwick(int n) : n(n), a(n, T()) {}
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

    void add(int x, T v)
    {
        for (int i = x + 1; i <= n; i += i & -i)
            a[i - 1] += v;
    }

    T sum(int x)
    {
        auto ans = T();
        for (int i = x + 1; i > 0; i -= i & -i)
            ans += a[i - 1];
        return ans;
    }

    T rangeSum(int l, int r)
    {
        if (l > r)
            return T(0);
        return sum(r) - sum(l - 1);
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, q;
    std::cin >> n >> m >> q;

    std::string s;
    std::cin >> s;

    std::vector in(m, std::array<int, 2>());
    for (auto &[l, r] : in)
    {
        std::cin >> l >> r;
        l--, r--;
    }

    Fenwick<int> ft(n + 1);

    auto get = [&](int start)
    {
        int left = start, right = n;
        int ans = start;

        while (left <= right)
        {
            int mid = std::midpoint(left, right);
            if (ft.rangeSum(start, mid) < mid - start + 1)
                ans = mid, right = mid - 1;
            else
                left = mid + 1;
        }

        return ans;
    };

    std::vector p(n + 1, n);
    int priority = 0;

    for (auto &[l, r] : in)
    {
        int cur = l;
        while (cur <= r)
        {
            cur = get(cur);
            if (cur > r)
                break;

            p[cur] = priority++;
            ft.add(cur, 1);
            cur++;
        }
    }

    int tot = 0;
    std::fill(std::begin(ft.a), std::end(ft.a), 0);
    int len = 0;

    for (int i = 0; i < n; i++)
    {
        if (p[i] != n)
            len++;
    }

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
            ft.add(p[i], 1), tot++;
    }

    while (q--)
    {
        int id;
        std::cin >> id;
        id--;

        if (s[id] == '1')
        {
            ft.add(p[id], -1);
            tot--;
        }
        else
        {
            ft.add(p[id], 1);
            tot++;
        }

        s[id] ^= '0' ^ '1';
        std::cout << std::min(len, tot) - ft.rangeSum(0, std::min(len, tot) - 1) << "\n";
    }

    return 0;
}