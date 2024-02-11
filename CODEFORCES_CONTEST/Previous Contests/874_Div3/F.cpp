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

constexpr int P = 1e9 + 7;
using Z = MInt<P>;

template <class Info>
struct SegmentTree
{
    int n;
    std::vector<Info> info;
    SegmentTree(int n = 0) : n(n), info(4 << std::__lg(n), Info()) {}
 
    template <typename T>
    SegmentTree(const std::vector<T> a) 
    {
        n = std::size(a);
        info.assign(4 << std::__lg(n), Info());
        std::function<void(int, int, int)> build;
        build = [&](int l, int r, int id)
        {
            if (l > r)
                return;
            if (l == r)
            {
                info[id] = Info(a[l], 1);
                return;
            }
 
            int m = (l + r) >> 1;
            build(l, m, id * 2 + 1);
            build(m + 1, r, id * 2 + 2);
            merge(id);
        }; 
        build(0, n - 1, 0);
    } 
    void merge(int id)
    {
        info[id] = info[id * 2 + 1] + info[id * 2 + 2];
    }
    void update(int id, int x, int nl, int nr, const Info &v)
    {
        if (nl > nr)
            return;
        if (nl == nr)
        {
            info[id] = info[id] + v;
            return;
        }
 
        int m = (nl + nr) >> 1;
        if (x <= m)
            update(2 * id + 1, x, nl, m, v);
        else
            update(2 * id + 2, x, m + 1, nr, v);
        merge(id);
    }
    void update(int x, const Info &v)
    {
        update(0, x, 0, n - 1, v);
    }
    Info get(int id, int l, int r, int nl, int nr)
    {
        if (r < nl or l > nr)
            return Info();
        if (l >= nl and r <= nr)
            return info[id];
 
        int m = (l + r) >> 1;
        return get(2 * id + 1, l, m, nl, nr) + get(2 * id + 2, m + 1, r, nl, nr);
    }
    Info get(int l, int r)
    {
        return get(0, 0, n - 1, l, r);
    };
};

struct Info
{
    Z prod;
    int zero;
    Info() : prod(1), zero(1) {}
    Info(Z prod, int zero) : prod(prod), zero(zero) {}
};

Info operator+(Info a, Info b)
{
    a.prod *= b.prod;
    a.zero |= b.zero;
    return a;
}

void solve()
{
    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(n);
    std::map<int, int> id, freq;
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        id[a[i]] = 0;
    }

    int index = 1;
    std::sort(std::begin(a), std::end(a));
    for (auto &[num, f] : id)
        f = index++;

    int add = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i] - a[i - 1] > 1)
            add++;
        id[a[i]] += add;
    }

    for (int i = 0; i < n; i++)
    {
        a[i] = id[a[i]];
        freq[a[i]]++;
    }

    SegmentTree<Info> st(a.back() + 1);
    for (int i = 0; i < st.n; i++)
        st.update(i, Info(freq[i], freq[i] != 0));

    Z ans = 0;
    for (int i = 0; i <= st.n - m; i++)
    {
        auto [prod, zero] = st.get(i, i + m - 1);
        ans += prod * zero;
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