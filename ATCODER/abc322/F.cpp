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
    int n;
    std::vector<Info> info;
    std::vector<Tag> tag;
    LazySegmentTree() : n(0) {}
    LazySegmentTree(int n_, Info v_ = Info()) { init(n_, v_); }

    template <class T>
    LazySegmentTree(const std::vector<T> init_) { init(init_); }

    void init(int n_, Info v_= Info()) { init(std::vector(n_, v_)); }
    template <class T>
    void init(std::vector<T> init_)
    {   
        n = init_.size();
        info.assign(4 << std::__lg(n), Info());
        tag.assign(4 << std::__lg(n), Tag());

        std::function<void(int, int, int)> build = [&](int id, int l, int r)
        {
            if (l > r)
                return;
            if (l == r)
            {
                info[id] = init_[l];
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
    int x = 0;
    void apply(Tag t) { x ^= t.x; }
};

struct Info
{
    std::array<i64, 2> pref{}, suff{}, ans{};
    int len = 0;

    Info() {}
    Info(std::array<i64, 2> pref, std::array<i64, 2> suff, 
        std::array<i64, 2> ans, int len) 
            : pref(pref), suff(suff), ans(ans), len(len) {}

    void apply(Tag t)
    {
        if (!t.x)
            return;

        std::swap(pref[0], pref[1]);
        std::swap(suff[0], suff[1]);
        std::swap(ans[0], ans[1]);
    }

    void get()
    {
        print(pref, suff, ans, len);
    }
};

Info operator+(const Info &a, const Info &b)
{
    Info c;
    for (int i = 0; i < 2; i++)
    {
        c.pref[i] = a.pref[i];
        if (a.pref[i] == a.len)
            c.pref[i] = std::max(c.pref[i], a.pref[i] + b.pref[i]);

        c.suff[i] = b.suff[i];
        if (b.suff[i] == b.len)
            c.suff[i] = std::max(c.suff[i], b.suff[i] + a.suff[i]);

        c.ans[i] = std::max({a.ans[i], b.ans[i], a.suff[i] + b.pref[i]});
        c.len = a.len + b.len;
    }

    return c;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, q;
    std::string s;
    std::cin >> n >> q >> s;

    Info();
    LazySegmentTree<Info, Tag> st(n);
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
            st.update(i, Info({0, 1}, {0, 1}, {0, 1}, 1));
        else
            st.update(i, Info({1, 0}, {1, 0}, {1, 0}, 1));
    }

    while (q--)
    {
        int c, L, R;
        std::cin >> c >> L >> R;

        L--, R--;
        if (c == 1)
            st.rangeApply(L, R, Tag(1));
        else
            std::cout << st.get(L, R).ans[1] << "\n";
    }
    
    return 0;
}