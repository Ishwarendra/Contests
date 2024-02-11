#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

template<typename T, class F = std::function<T(const T&, const T&)>>
struct SegmentTree
{
    const int n;
    const T null_val;
    std::vector<T> tree;
    F f;

    template <typename G>
    SegmentTree(const std::vector<G> in, const T null_val, const F& f) 
        : n(int(std::size(in))), tree(2 * n, null_val), f(f), null_val(null_val)
    {
        for (int i = 0; i < n; ++i)
            tree[i + n] = in[i];

        for (int i = n - 1; i >= 0; i--)
            tree[i] = f(tree[i << 1], tree[i << 1 | 1]);
    }
    void add(int id, T x)
    {
        T val = x - get(id, id);
        update(id, val);
    }
    void update(int id, T val)
    {
        for (tree[id += n] = val; id >>= 1; )
            tree[id] = f(tree[id << 1], tree[(id << 1) | 1]);
    }
    T get(int l, int r) 
    {
        T resL = null_val, resR = null_val;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1)
                resL = f(resL, tree[l++]);
            if (r & 1)
                resR = f(tree[--r], resR);
        }

        return f(resL, resR);
    }
};

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];
    a.emplace_back(n);
    n++;

    SegmentTree<int> max(a, 0, [&](int x, int y)
    {
        return std::max(x, y);
    });

    i64 m;
    std::cin >> m;

    std::vector<int> pg(n), ng(n), stack;
    for (int i = 0; i < n; i++)
    {
        while (!stack.empty() and a[stack.back()] <= a[i])
            stack.pop_back();
        pg[i] = (stack.empty() ? -1 : stack.back());
        stack.emplace_back(i);
    }

    stack.clear();
    for (int i = n - 1; i >= 0; i--)
    {
        while (!stack.empty() and a[stack.back()] < a[i])
            stack.pop_back();
        ng[i] = (stack.empty() ? n - 1 : stack.back());
        stack.emplace_back(i);
    }

    std::vector<i64> cnt(n + 1);

    for (int i = 0; i < n; i++)
    {
        int x = pg[i];
        int y = i;

        int h = std::abs(a[i] - max.get(x + 1, y - 1));
        int w = i - pg[i] - 1;
        cnt[w] += h;

        x = i;
        y = ng[i];

        h = std::abs(a[i] - max.get(x + 1, y - 1));
        w = ng[i] - i - 1;

        if (i < n - 1)
            cnt[w] += h;
    }

    i64 ans = 0;
    
    for (int i = n - 1; i > 0 and m > 0; i--)
    {
        i64 have = cnt[i];

        if (i * have >= m)
        {
            ans += m - (m + i - 1) / i;
            m = 0;
        }
        else
        {
            ans += have * (i - 1);
            m -= have * i;
        }
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