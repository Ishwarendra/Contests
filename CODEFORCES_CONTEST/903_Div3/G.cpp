#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

template<class T>
T power(T a, i64 b)
{
    T res = 1;
    for (; b; b /= 2, a *= a)
    {
        if (b % 2)
            res *= a;
    }
    return res;
}

template<class T>
T inverse(T a, T m)
{
    T u = 0, v = 1;
    while (a != 0)
    {
        T t = m / a;
        m -= t * a;
        u -= t * v;
        std::swap(a, m);
        std::swap(u, v);
    }
    assert(m == 1);
    return u;
}

template<int P>
struct MInt
{
    int x;
    constexpr MInt() : x{} {}
    constexpr MInt(i64 x) : x{norm(x % getMod())} {}

    static int Mod;
    constexpr static int getMod()
    {
        if (P > 0)
            return P;
        else
            return Mod;
    }
    constexpr static void setMod(int Mod_) { Mod = Mod_; }
    constexpr int norm(int x) const
    {
        if (x < 0)
            x += getMod();

        if (x >= getMod())
            x -= getMod();

        return x;
    }
    constexpr int val() const { return x; }
    explicit constexpr operator int() const { return x; }
    constexpr MInt operator-() const
    {
        MInt res;
        res.x = norm(getMod() - x);
        return res;
    }
    constexpr MInt inv() const
    {
        assert(x != 0);
        return MInt(inverse(x, P));
    }
    constexpr MInt &operator*=(MInt rhs) &
    {
        x = 1LL * x * rhs.x % getMod();
        return *this;
    }
    constexpr MInt &operator+=(MInt rhs) &
    {
        x = norm(x + rhs.x);
        return *this;
    }
    constexpr MInt &operator-=(MInt rhs) &
    {
        x = norm(x - rhs.x);
        return *this;
    }
    constexpr MInt &operator/=(MInt rhs) &
    {
        return *this *= rhs.inv();
    }
    friend constexpr MInt operator*(MInt lhs, MInt rhs)
    {
        MInt res = lhs;
        res *= rhs;
        return res;
    }
    friend constexpr MInt operator+(MInt lhs, MInt rhs)
    {
        MInt res = lhs;
        res += rhs;
        return res;
    }
    friend constexpr MInt operator-(MInt lhs, MInt rhs)
    {
        MInt res = lhs;
        res -= rhs;
        return res;
    }
    friend constexpr MInt operator/(MInt lhs, MInt rhs)
    {
        MInt res = lhs;
        res /= rhs;
        return res;
    }
    friend constexpr std::istream &operator>>(std::istream &is, MInt &a)
    {
        i64 v;
        is >> v;
        a = MInt(v);
        return is;
    }
    friend constexpr std::ostream &operator<<(std::ostream &os, const MInt &a) { return os << a.val(); }
    friend constexpr bool operator==(MInt lhs, MInt rhs) { return lhs.val() == rhs.val(); }
    friend constexpr bool operator!=(MInt lhs, MInt rhs) { return lhs.val() != rhs.val(); }
};

template<>
int MInt<0>::Mod = 1;

template<int V, int P>
constexpr MInt<P> CInv = MInt<P>(V).inv();

constexpr int P = 26;
using Z = MInt<P>;

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
    Z add;
    Tag(Z add = 0) : add(add) {}

    void apply(Tag t) { add += t.add; }
};

struct Info
{
    std::array<int, 2> first { -1, -1}, last { -1, -1};
    bool good = true;

    void apply(Tag t)
    {
        for (auto &p : first)
        {
            if (p != -1)
                p += t.add.val(), p %= 26;
        }

        for (auto &p : last)
        {
            if (p != -1)
                p += t.add.val(), p %= 26;
        }
    }

    void disp() { print(first, last, good); }
};

Info operator+(Info a, Info b)
{
    if (a.first == std::array { -1, -1})
        return b;
    if (b.first == std::array { -1, -1})
        return a;

    Info c;
    c.good = a.good and b.good;

    c.first = a.first;
    c.last = b.last;

    if (c.first[1] == -1)
        c.first[1] = b.first[0];

    if (c.last[0] == -1)
        c.last[0] = a.last[1];

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (i == 0 and j == 1)
                continue;

            if (a.last[i] == b.first[j] and a.last[i] != -1)
                c.good = false;
        }
    }

    // a.disp(), b.disp(), c.disp();
    // std::cout << std::endl;

    return c;
}

void solve()
{
    int n, q;
    std::cin >> n >> q;

    std::string s;
    std::cin >> s;

    LazySegmentTree<Info, Tag> st(n);
    for (int i = 0; i < n; i++)
    {
        Info info;
        info.first[0] = info.last[1] = s[i] - 'a';
        st.update(i, info);
    }

    while (q--)
    {
        int t;
        std::cin >> t;

        if (t == 1)
        {
            int l, r, x;
            std::cin >> l >> r >> x;
            l--, r--;

            st.rangeApply(l, r, Tag(x));
        }
        else
        {
            int l, r;
            std::cin >> l >> r;
            l--, r--;
            if (st.get(l, r).good)
                std::cout << "YES\n";
            else
                std::cout << "NO\n";
        }
    }
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