#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

template<class Info,
    class Merge = std::plus<Info>>
struct SegmentTree
{
    const int n;
    const Merge merge;
    std::vector<Info> info;
    SegmentTree(int n = 0) : n(n), merge(Merge()), info(4 << std::__lg(n)) {}
 
    template <typename T>
    SegmentTree(const std::vector<T> a) : SegmentTree(std::size(a))
    {
        std::function<void(int, int, int)> build;
        build = [&](int l, int r, int id)
        {
            if (l > r)
                return;
            if (l == r)
            {
                info[id] = Info(a[l], l);
                return;
            }
 
            int m = (l + r) >> 1;
            build(l, m, id * 2 + 1);
            build(m + 1, r, id * 2 + 2);
            pull(id);
        }; 
        build(0, n - 1, 0);
    } 
    void pull(int id)
    {
        info[id] = merge(info[id * 2 + 1], info[id * 2 + 2]);
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
    void update(int x, const Info &v)
    {
        update(0, 0, n - 1, x, v);
    }
    Info get(int id, int l, int r, int a, int b)
    {
        if (r < a or l > b)
            return Info();
        if (l >= a and r <= b)
            return info[id];
 
        int m = (l + r) >> 1;
        return merge(get(2 * id + 1, l, m, a, b), get(2 * id + 2, m + 1, r, a, b));
    }
    Info get(int l, int r)
    {
        return get(0, 0, n - 1, l, r);
    };

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

struct Max
{
    int x;
    Max(int x = 0) : x(x) {}
};

Max operator+(const Max &a, const Max &b)
{
    return Max(std::max(a.x, b.x));
}

void solve()
{
    int n, m;
    std::cin >> n >> m;

    SegmentTree<Max> dp(n + 1);
    std::vector<std::pair<int, int>> a(m);
    std::vector<int> diff(n + 2), cover(n + 2);

    for (auto &[l, r] : a)
    {
        std::cin >> l >> r;
        diff[r + 1]--;
        diff[l]++;
    }

    std::sort(std::begin(a), std::end(a));

    for (int i = 1; i < n + 2; i++)
        diff[i] += diff[i - 1];

    std::multiset<int> least;
    int id = 0, rem_id = 0;

    for (int i = 1; i <= n; i++)
    {
        while (rem_id < id and a[rem_id].second < i)
            least.erase(least.find(a[rem_id].first)), rem_id++;

        while (id < m and a[id].first <= i)
            least.emplace(a[id].first), id++;

        if (!least.empty())
            cover[i] = *std::begin(least);
    }

    for (int i = 1; i <= n; i++)
    {
        if (cover[i] == 0)
            continue;

        int cur = dp.get(0, cover[i] - 1).x;
        cur += diff[i];
        int prev = dp.get(i, i).x;

        if (prev < cur)
            dp.update(i, Max(cur));
    }

    std::cout << dp.get(0, n).x << "\n";
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