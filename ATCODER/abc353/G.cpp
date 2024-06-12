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

constexpr i64 inf = 5e18;

struct Info
{
    i64 x;
    Info(i64 x = -inf) : x(x) {}
};

Info operator+(const Info &a, const Info &b)
{
    return Info(std::max(a.x, b.x));
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    i64 c;
    std::cin >> n >> c >> m;
    
    std::vector<std::pair<int, i64>> a(m);
    for (auto &[t, p] : a)
    {
        std::cin >> t >> p;
        t--;
    }
    
    SegmentTree<Info> max1(n), max2(n);
    max1.update(0, 0); // assuming t_j is smaller town
    max2.update(0, 0); // assuming t_j is larger town
    std::vector<i64> dp(m + 1, 0), best(n, 0);
    
    for (int i = 1; i <= m; i++)
    {
        // dp[i] = dp[j] + C * t_j - C * t + p, t <= t_j
        // dp[i] = dp[j] + C * t - C * t_j + p, t > t_j
        auto [t, p] = a[i - 1];
        
        i64 v1 = max1.get(0, t).x;
        i64 v2 = max2.get(t + 1, n - 1).x;

        dp[i] = std::max(v1 - c * t + p, v2 + c * t + p);
        
        max1.update(t, Info(dp[i] + c * t) + max1.get(t, t));
        max2.update(t, Info(dp[i] - c * t) + max2.get(t, t));
    }
    
    std::cout << *std::max_element(std::begin(dp), std::end(dp));
    
    return 0;
}