#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

template <class Info, class Tag>
struct LazySegmentTree
{
    const int n;
    std::vector<Info> info;
    std::vector<Tag> tag;

    LazySegmentTree(int n = 0) : n(n), info(4 << std::__lg(n)), tag(4 << std::__lg(n)) {}

    template <class T>
    LazySegmentTree(const std::vector<T> a) : LazySegmentTree(std::size(a))
    {
        std::function<void(int, int, int)> build;
        build = [&](int id, int l, int r)
        {
            if (l > r)
                return;
            if (l == r)
            {
                info[id] = Info(a[l]);
                return;
            }

            int m = (l + r) >> 1;
            build(2 * id + 1, l, m);
            build(2 * id + 2, m + 1, r);
            pull(id);
        }; build(0, 0, n - 1);
    }

    void pull(int id) { info[id] = info[2 * id + 1] + info[2 * id + 2]; }
    void apply(int id, const Tag &t)
    {
        info[id].apply(t);
        tag[id].apply(t);
    }
    void push(int id)
    {
        apply(2 * id + 1, tag[id]);
        apply(2 * id + 2, tag[id]);
        tag[id] = Tag();
    }

    void update(int id, int l, int r, int x, const Info &v)
    {
        if (l > r)
            return;
        if (l == r)
        {
            info[id] = v;
            return;
        }

        int m = (l + r) >> 1;
        if (x <= m)
            update(2 * id + 1, l, m, x, v);
        else
            update(2 * id + 2, m + 1, r, x, v);
        pull(id);
    }

    void update(int x, const Info &v) { return update(0, 0, n - 1, x, v); }

    Info get(int id, int l, int r, int a, int b)
    {
        if (b < l or r < a)
            return Info();

        if (a <= l and r <= b)
            return info[id];

        int m = (l + r) >> 1;
        push(id);
        return get(2 * id + 1, l, m, a, b) + get(2 * id + 2, m + 1, r, a, b);
    }

    Info get(int a, int b) { return get(0, 0, n - 1, a, b); }

    void rangeApply(int id, int l, int r, int a, int b, const Tag &v)
    {
        if (b < l or r < a)
            return;

        if (a <= l and r <= b)
        {
            apply(id, v);
            return;
        }
        int m = (l + r) >> 1;
        push(id);
        rangeApply(2 * id + 1, l, m, a, b, v);
        rangeApply(2 * id + 2, m + 1, r, a, b, v);
        pull(id);
    }

    void rangeApply(int a, int b, const Tag &v) { rangeApply(0, 0, n - 1, a, b, v); }
    template <class F>
    int findFirst(int id, int l, int r, int a, int b, F pred)
    {
        if (r < a or l > b or !pred(info[id]))
            return -1;

        if (l == r)
            return l;

        int m = (l + r) >> 1;
        int res = findFirst(2 * id + 1, l, m, a, b, pred);
        if (res == -1)
            res = findFirst(2 * id + 2, m + 1, r, a, b, pred);

        return res;
    }

    template <class F>
    int findFirst(int l, int r, F pred) { return findFirst(0, 0, n - 1, l, r, pred); }

    template <class F>
    int findLast(int id, int l, int r, int a, int b, F pred)
    {
        if (r < a or l > b or !pred(info[id]))
            return -1;

        if (l == r)
            return l;

        int m = (l + r) >> 1;
        int res = findLast(2 * id + 2, m + 1, r, a, b, pred);
        
        if (res == -1)
            res = findLast(2 * id + 1, l, m, a, b, pred);

        return res;
    }

    template <class F>
    int findLast(int l, int r, F pred) { return findLast(0, 0, n - 1, l, r, pred); }
};

struct Tag
{
    i64 add;
    Tag(i64 add = 0) : add(add) {}

    void apply(Tag t) { add += t.add; }
};

struct Info
{
    i64 sum;
    Info(i64 sum = 0) : sum(sum) {}

    void apply(Tag t) { sum += t.add; }
};

Info operator+(Info a, Info b)
{
    a.sum += b.sum;
    return a;
}

void solve()
{
    int q;
    std::cin >> q;

    std::vector<std::array<i64, 3>> qry;
    std::vector<std::vector<int>> adj(1);

    int n = 1;

    while (q--)  
    {
        int t;
        std::cin >> t;

        if (t == 1)
        {
            int u;
            std::cin >> u;
            qry.push_back({t, n + 1, 0});

            adj.emplace_back();
            u--;
            adj[u].emplace_back(n);
            n++;
        }
        else
        {
            int v, x;
            std::cin >> v >> x;
            qry.push_back({t, v, x});
        }
    }

    std::vector<int> tin(n), tout(n);
    int time = -1;

    auto dfs = [&](auto &&self, int u) -> void
    {
        tin[u] = ++time;
        for (int v : adj[u])
            self(self, v);
        tout[u] = time;
    }; dfs(dfs, 0);

    LazySegmentTree<Info, Tag> seg(n + 1);

    for (auto &[type, u, x] : qry)
    {
        u--;

        if (type == 2)
            seg.rangeApply(tin[u], tout[u], Tag(x));
        else
            seg.rangeApply(tin[u], tout[u], Tag(-seg.get(tin[u], tin[u]).sum));
    }
    std::vector<i64> ans(n);
    for (int i = 0; i < n; i++)
        ans[tin[i]] = seg.get(tin[i], tin[i]).sum;
    
    for (int i = 0; i < n; i++)
        std::cout << ans[tin[i]] << " \n"[i == n - 1];
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