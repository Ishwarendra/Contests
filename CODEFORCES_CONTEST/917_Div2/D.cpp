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

constexpr int P = 998244353;
using Z = MInt<P>;

template <typename T>
struct Fenwick 
{
    const int n;
    std::vector<T> a;
    
    Fenwick() {}
    Fenwick(int n) : n(n), a(n, T()) {}
    template <class G>
    Fenwick(const std::vector<G> in) : Fenwick(std::size(in))
    {
        for (int i = 1; i <= n; i++)
        {
            a[i - 1] += in[i - 1];
            if (i + (i & -i) <= n)
                a[i - 1 + (i & -i)] += a[i - 1];
        }
    }
    
    void add(int x, T v) 
    {
        for (int i = x + 1; i <= n; i += i & -i) 
            a[i - 1] += v;
    }
    
    T sum(int x) 
    {
        auto ans = T();
        for (int i = x + 1; i > 0; i -= i & -i) 
            ans += a[i - 1];
        return ans;
    }
    
    T rangeSum(int l, int r) 
    { 
        if (l > r)
            return T(0);
        return sum(r) - sum(l - 1); 
    }
};

Z sum(auto a, auto d, auto n)
{
    if (n < 0)
        return 0;

    Z ans = Z(n) / 2;
    ans *= (Z(a) * 2 + Z(n - 1) * d);
    return ans;
}

void solve()
{
    int n, k;
    std::cin >> n >> k;

    std::vector<int> p(n), q(k);
    for (int i = 0; i < n; i++)
        std::cin >> p[i];
    for (int i = 0; i < k; i++)
        std::cin >> q[i];

    std::vector<Z> addp(n), addq(k);
    Fenwick<int> ftp(2 * n), ftq(k);

    for (int i = n - 1; i >= 0; i--)
    {
        addp[i] += ftp.sum(p[i] - 1);
        ftp.add(p[i], 1);
    }

    for (int i = k - 1; i >= 0; i--)
    {
        addq[i] += ftq.sum(q[i] - 1);
        ftq.add(q[i], 1);
    }

    Z totq = std::accumulate(std::begin(addq), std::end(addq), Z(0));
    std::fill(std::begin(ftp.a), std::end(ftp.a), 0);
    std::fill(std::begin(ftq.a), std::end(ftq.a), 0);

    auto get = [&](i64 a, i64 d)
    {
        return std::max<i64>(0, k + 1 - a / d);
    };

    Z ans = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        ans += totq;

        int x = p[i];

        int k_ = k;
        i64 prev = 0;
        int done = 0;
        while (x / 2 <= 2 * n - 1 and k_--)
        {
            auto y = x;
            i64 add = 0;

            int k__ = k;
            while (y and k__--)
            {
                int limit = std::min(2 * n - 1, y);
                add += ftp.rangeSum(0, std::min(y, limit));
                y /= 2;
            }

            ans += add;
            prev = add;

            x *= 2;
            done++;
        }

        int dis = ftp.rangeSum(0, std::min(x, 2 * n - 1));
        if (dis != 0 and done < k)
        {
            int rem = k - done;
            prev += dis;

            auto t = get(prev, dis);
        }

        ftp.add(p[i], 1);
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