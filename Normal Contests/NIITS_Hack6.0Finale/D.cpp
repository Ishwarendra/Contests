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
};

struct Tag
{
    bool flip;
    Tag(bool flip = false) : flip(flip) {}

    void apply(Tag t)
    {
        if (t.flip)
            flip = !flip;
    }
};

struct Info
{
    int sum;
    int pmin;
    int smax;
    Info(int sum = 0, int pmin = 0, int smax = 0) : sum(sum), pmin(pmin), smax(smax) {}

    void apply(Tag t)
    {
        if (t.flip)
        {
            sum = -sum;
            std::swap(pmin, smax);
            pmin *= -1;
            smax *= -1;
        }
    }

    void disp() const
    {
        print(sum, pmin, smax);
    }
};

Info operator+(const Info &a, const Info &b)
{
    int sum = a.sum + b.sum;
    int pmin = std::min(a.pmin, a.sum + b.pmin);
    int smax = std::max(b.smax, b.sum + a.smax);

    return Info(sum, pmin, smax);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, q;
    std::cin >> n >> q;

    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    std::vector<int> sz(n, 1), par(n), dep(n), tin(n), top(n);
    auto dfs_sz = [&](auto && self, int u, int p) -> void
    {
        par[u] = p;
        if (p != u)
            adj[u].erase(std::find(std::begin(adj[u]), std::end(adj[u]), p));

        for (auto &v : adj[u])
        {
            dep[v] = dep[u] + 1;
            self(self, v, u);
            sz[u] += sz[v];

            if (sz[v] > sz[adj[u][0]])
                std::swap(v, adj[u][0]);
        }
    }; dfs_sz(dfs_sz, 0, 0);

    int time = 0;
    auto dfs = [&](auto && self, int u) -> void
    {
        tin[u] = time++;
        for (auto v : adj[u])
        {
            top[v] = v == adj[u][0] ? top[u] : v;
            self(self, v);
        }
    }; dfs(dfs, 0);

    const int m = std::__lg(n) + 2;
    std::vector dp(n, std::vector(m, 0));
    for (int j = 0; j < m; j++)
    {
        for (int i = 0; i < n; i++)
        {
            if (j == 0)
                dp[i][j] = par[i];
            else
                dp[i][j] = dp[dp[i][j - 1]][j - 1];
        }
    }

    auto lca = [&](int u, int v) -> std::pair<int, int>
    {
        int swap = 0;
        if (dep[u] < dep[v])
            std::swap(u, v), swap = 1;

        int diff = dep[u] - dep[v];
        for (int pos = m - 1; pos >= 0; pos--)
        {
            if ((diff >> pos) & 1)
                u = dp[u][pos];
        }

        if (u == v)
            return {u, 0};

        for (int pos = m - 1; pos >= 0; pos--)
        {
            if (dp[u][pos] != dp[v][pos])
                u = dp[u][pos], v = dp[v][pos];
        }

        return swap ? std::pair {v, 1} : std::pair {u, 1};
    };

    std::string s;
    std::cin >> s;

    LazySegmentTree<Info, Tag> st(n), revst(n);;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
        {
            st.update(tin[i], Info(1, 0, 1));
            revst.update(n - 1 - tin[i], Info(1, 0, 1));
        }
        else
        {
            st.update(tin[i], Info(-1, -1, 0));
            revst.update(n - 1 - tin[i], Info(-1, -1, 0));
        }
    }

    auto update = [&](int u, int v, Tag t)
    {
        st.rangeApply(tin[u], tin[v], t);
        revst.rangeApply(n - 1 - tin[v], n - 1 - tin[u], t);
    };

    auto fetch = [&](int i, bool rev) { return rev ? n - 1 - i : i; };

    while (q--)
    {
        int t, u, v;
        std::cin >> t >> u >> v;
        u--, v--;

        if (t == 2)
        {
            // while (top[u] != top[v])
            // {
            //     if (dep[top[u]] < dep[top[v]])
            //         std::swap(u, v);

            //     update(top[u], u, Tag(true));
            //     u = par[top[u]];
            // }

            // if (dep[u] < dep[v])
            //     std::swap(u, v);

            // update(v, u, Tag(true));
        }
        else
        {
            auto get = [&](auto &seg, int u, int v, bool rev)
            {
                Info down;
                while (top[u] != top[v])
                {
                    if (dep[top[u]] < dep[top[v]])
                        std::swap(u, v);

                    if (rev)
                        down = down + seg.get(fetch(tin[u], rev), fetch(tin[top[u]], rev));
                    else
                        down = seg.get(fetch(tin[top[u]], rev), fetch(tin[u], rev)) + down;

                    u = par[top[u]];
                }

                if (dep[u] < dep[v])
                    std::swap(u, v);

                if (rev)
                    down = down + seg.get(fetch(tin[u], rev), fetch(tin[v], rev));
                else
                    down = seg.get(fetch(tin[v], rev), fetch(tin[u], rev)) + down;

                return down;
            };

            auto [l, real] = lca(u, v);
            if (real)
                l = dp[l][0];

            Info down;

            if (l != v and l != u)
            {
                auto [lu, __] = lca(u, v);
                down = get(revst, u, lu, true);
                down.disp();
                down = down + st.get(tin[l], tin[l]);

                auto [ld, _] = lca(v, u);
                down = down + get(st, ld, v, false);
            }
            else
            {
                if (v == l)
                    down = get(revst, u, v, true);
                else
                    down = get(st, u, v, false);
            }

            auto [sum, pmin_d, smax_d] = down;
            if (sum == 0 and pmin_d >= 0)
                std::cout << "YES\n";
            else
                std::cout << "NO\n";
        }
    }

    return 0;
}