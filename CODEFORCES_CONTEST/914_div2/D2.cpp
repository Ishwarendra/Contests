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

constexpr int inf = 1e9 + 1;

struct MinTag
{
    int min;
    MinTag(int min = inf) : min(min) {}

    void apply(MinTag t) { min = std::min(min, t.min); }
};

struct Min
{
    int min;
    Min(int min = inf) : min(min) {}

    void apply(MinTag t) { min = std::min(min, t.min); }
};

struct MaxTag
{
    int max;
    MaxTag(int max = -inf) : max(max) {}

    void apply(MaxTag t) { max = std::max(max, t.max); }
};

struct Max
{
    int max;
    Max(int max = -inf) : max(max) {}

    void apply(MaxTag t) { max = std::max(max, t.max); }
};

Min operator+(Min a, Min b) { return {std::min(a.min, b.min)}; }
Max operator+(Max a, Max b) { return {std::max(a.max, b.max)}; }

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n), b(n);

    LazySegmentTree<Max, MaxTag> max(n);
    LazySegmentTree<Min, MinTag> min(n);

    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        max.update(i, {a[i]});
    }

    for (int i = 0; i < n; i++)
    {
        std::cin >> b[i];
        min.update(i, {b[i]});
    }

    std::vector<std::array<int, 2>> pos;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != b[i])
            pos.push_back({b[i], i});
    }

    std::sort(std::begin(pos), std::end(pos));
    for (auto &[_, i] : pos)
    {
        if (max.get(i, i).max > b[i])
        {
            std::cout << "NO\n";
            return;
        }

        int left = 0, right = i - 1;
        int ans = i + 1;

        while (left <= right)
        {
            int mid = std::midpoint(left, right);
            int max_a = max.get(mid, i).max;
            int min_b = min.get(mid, i).min;

            if (max_a <= b[i] and min_b >= b[i])
                ans = mid, right = mid - 1;
            else
                left = mid + 1;
        }

        left = i + 1, right = n - 1;
        int ansr = i - 1;
        while (left <= right)
        {
            int mid = std::midpoint(left, right);
            int max_a = max.get(i, mid).max;
            int min_b = min.get(i, mid).min; 

            if (max_a <= b[i] and min_b >= b[i])
                ansr = mid, left = mid + 1;
            else
                right = mid - 1;
        }

        int val_left = max.get(ans, i).max;
        int val_right = max.get(i, ansr).max;
        if (val_left != b[i] and val_right != b[i])
        {
            std::cout << "NO\n";
            return;
        }

        if (val_left == b[i])
            max.rangeApply(ans, i, {b[i]});
        if (val_right == b[i])
            max.rangeApply(i, ansr, {b[i]});
    }

    std::cout << "YES\n";
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