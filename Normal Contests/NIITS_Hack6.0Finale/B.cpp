#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
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

struct Info
{
    int o, c, q, sum, pmin;
    Info(int o = 0, int c = 0, int q = 0, int sum = 0, int pmin = 0)
        : o(o), c(c), q(q), sum(sum), pmin(pmin) {};
};

Info operator+(const Info &a, const Info &b)
{
    int sum = a.sum + b.sum;
    int pmin = std::min(a.pmin, b.pmin + a.sum);
    return Info(a.o + b.o, a.c + b.c, a.q + b.q, sum, pmin);
}

void solve()
{
    int n;
    std::string s;
    std::cin >> n >> s;

    auto rev = s;
    std::reverse(std::begin(rev), std::end(rev));
    for (auto &ch : rev)
    {
        if (ch != '?')
            ch ^= ')' ^ '(';
    }

    SegmentTree<Info> st(n), revst(n);
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
            st.update(i, Info(1, 0, 0, 1, 0));
        else if (s[i] == ')')
            st.update(i, Info(0, -1, 0, -1, -1));
        else
            st.update(i, Info(0, 0, 1, 1, 0));

        if (rev[i] == '(')
            revst.update(i, Info(1, 0, 0, 1, 0));
        else if (rev[i] == ')')
            revst.update(i, Info(0, -1, 0, -1, -1));
        else
            revst.update(i, Info(0, 0, 1, 1, 0));
    }

    int q;
    std::cin >> q;

    while (q--)
    {
        int t;
        std::cin >> t;

        if (t == 1)
        {
            int id;
            char ch;
            std::cin >> id >> ch;

            id--;
            s[id] = ch;
            rev[n - 1 - id] = (ch == '?' ? ch : (ch ^ '(' ^ ')'));

            if (s[id] == '(')
                st.update(id, Info(1, 0, 0, 1, 0));
            else if (s[id] == ')')
                st.update(id, Info(0, -1, 0, -1, -1));
            else
                st.update(id, Info(0, 0, 1, 1, 0));

            if (rev[n - 1 - id] == '(')
                revst.update(n - 1 - id, Info(1, 0, 0, 1, 0));
            else if (rev[n - 1 - id] == ')')
                revst.update(n - 1 - id, Info(0, -1, 0, -1, -1));
            else
                revst.update(n - 1 - id, Info(0, 0, 1, 1, 0));
        }
        else
        {
            int l, r;
            std::cin >> l >> r;
            l--, r--;

            int len = (r - l + 1);
            if (len % 2)
            {
                std::cout << "NO\n";
                continue;
            }

            auto [o, c, q, sum, pmin] = st.get(l, r);
            auto rpmin = revst.get(n - 1 - r, n - 1 - l).pmin;
            if (pmin >= 0 and rpmin >= 0 and o * 2 <= len and std::abs(c) * 2 <= len)
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