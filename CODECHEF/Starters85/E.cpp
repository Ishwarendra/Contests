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

    Fenwick() {};
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

    int kth(T k)
    {
        int x = 0;
        for (int i = 1 << std::__lg(n); i; i /= 2)
        {
            if (x + i <= n && k >= a[x + i - 1])
                x += i, k -= a[x - 1];
        }
        return x;
    }
};

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    std::set<std::pair<int, int>> m;
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    auto primeFactor = [&](int x)
    {
        std::vector<int> pf;
        for (int i = 2; 1LL * i * i <= x; i++)
        {
            if (x % i == 0)
                pf.emplace_back(i);

            while (x % i == 0)
                x /= i;
        }

        if (x > 1)
            pf.emplace_back(x);

        return pf;
    };

    std::sort(std::begin(a), std::end(a));
    for (int i = 0; i < n; i++)
        m.emplace(a[i], i);

    std::map<int, std::set<int>> pos;
    for (int i = 0; i < n; i++)
    {
        auto pf = primeFactor(a[i]);
        for (auto x : pf)
            pos[x].emplace(i);
    }

    auto clear = [&](int id)
    {
        m.erase(m.lower_bound({a[id], -1}));
        auto pf = primeFactor(a[id]);

        for (auto x : pf)
            pos[x].erase(id);
    };

    int q;
    std::cin >> q;

    while (q--)
    {
        int X;
        std::cin >> X;

        auto pfx = primeFactor(X);
        int id = n;
        for (auto x : pfx)
        {
            if (pos[x].empty())
                continue;

            id = std::min(id, *std::begin(pos[x]));
        }

        if (id == n)        
            id = std::begin(m)->second;

        clear(id);
        std::cout << a[id] << " \n"[q == 0];
    }
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