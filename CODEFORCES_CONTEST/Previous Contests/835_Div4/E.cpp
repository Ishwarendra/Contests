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

    Fenwick(int n) : n(n), a(n) {}
    template<typename G>
    Fenwick(const std::vector<G> in) : Fenwick((int)std::size(in))
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
        for (int i = x + 1; i <= n; i += i & -i) {
            a[i - 1] += v;
        }
    }
    T sum(int x)
    {
        T ans = 0;
        x++;
        for (int i = x; i > 0; i -= i & -i) {
            ans += a[i - 1];
        }
        return ans;
    }
    T rangeSum(int l, int r)
    {
        if (l - 1 < 0)
            return sum(r);

        return sum(r) - sum(l - 1);
    }
};

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    std::array<int, 2> last{n - 1, 0};
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        if (a[i] == 1)
            last[1] = std::max(last[1], i);
        else
            last[0] = std::min(last[0], i);
    }

    auto calc = [&]()
    {
        Fenwick<int> ft(3);
        i64 inv = 0;
        for (int i = 0; i < n; i++)
        {
            inv += ft.rangeSum(a[i] + 1, 2);
            ft.add(a[i], 1);
        }

        return inv;
    };

    i64 ans = calc();
    a[last[0]] ^= 1; 
    ans = std::max(ans, calc());
    a[last[1]] ^= 1, a[last[0]] ^= 1;
    ans = std::max(ans, calc());

    std::cout << ans << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    while (t--)
        solve();

    return 0;
}