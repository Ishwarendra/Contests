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

constexpr int inf = 1e9;

struct Info
{
    int x;
    Info(int x = -inf) : x(x) {}
};

Info operator+(const Info &a, const Info &b)
{
    return Info(std::max(a.x, b.x));
}

void solve()
{
    std::string s;
    std::cin >> s;
    
    int n = std::size(s);
    std::vector<int> _bal(n);
    _bal[0] = s[0] == '(' ? 1 : -1;
    for (int i = 1; i < n; i++)  
    {
        _bal[i] = _bal[i - 1];
        if (s[i] == '(')
            _bal[i]++;
        else
            _bal[i]--;
    }
    
    auto bal = [&](int l, int r)
    {
        if (l < 0 or r < 0)
            return 0;
        return _bal[r] - (l ? _bal[l - 1] : 0);
    };
    
    // [l, r] is ok to invert if 
    // bal(r) = bal(l - 1) and bal(r) <= 2 * bal(l - 1)
    
    std::map<int, std::vector<int>> pos;
    SegmentTree<Info> max(n);
    for (int i = 0; i < n; i++)
    {
        max.update(i, bal(0, i));
        pos[bal(0, i)].emplace_back(i);
    }
    
    i64 ans = 0;
    for (auto &[b, p] : pos)
    {
        for (int st = 0; int i : p)
        {
            auto id = max.findFirst(i, n - 1, [&](Info info)
            {
                return info.x > 2 * _bal[i];
            });
            
            if (id == -1)
                id = n;
            
            auto en = std::upper_bound(std::begin(p), std::end(p), id) - std::begin(p);
            ans += en - st - 1;
            st++;
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