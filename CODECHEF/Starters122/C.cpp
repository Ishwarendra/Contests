#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
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

struct Comb 
{
    int n;
    std::vector<Z> _fac;
    std::vector<Z> _invfac;
    std::vector<Z> _inv;
    
    Comb() : n{0}, _fac{1}, _invfac{1}, _inv{0} {}
    Comb(int n) : Comb() { init(n); }
    
    void init(int m) 
    {
        if (m <= n) return;
        _fac.resize(m + 1);
        _invfac.resize(m + 1);
        _inv.resize(m + 1);
        
        for (int i = n + 1; i <= m; i++) 
            _fac[i] = _fac[i - 1] * i;
        
        _invfac[m] = _fac[m].inv();
        for (int i = m; i > n; i--) 
        {
            _invfac[i - 1] = _invfac[i] * i;
            _inv[i] = _invfac[i] * _fac[i - 1];
        }
        n = m;
    }
    
    Z fac(int m) 
    {
        if (m > n) init(2 * m);
        return _fac[m];
    }
    Z invfac(int m) 
    {
        if (m > n) init(2 * m);
        return _invfac[m];
    }
    Z inv(int m) 
    {
        if (m > n) init(2 * m);
        return _inv[m];
    }
    Z binom(int n, int m) 
    {
        if (n < m || m < 0) return 0;
        return fac(n) * invfac(m) * invfac(n - m);
    }
} comb;

void solve()
{
    int n;
    std::cin >> n;

    std::vector a(n, std::vector(n, 0));
    std::map<int, int> m;

    const int k = n * (n + 1) / 2;
    std::map<int, int> _;
    for (int i = 1; i <= n * n; i++)
        _[i % k]++;

    auto par = [&](int x)
    {
        return _[x % k] % 2;
    };

    std::set<int> present;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cin >> a[i][j];
            if (a[i][j] == 0)
                a[i][j] = -1;
            else
                present.emplace(a[i][j]);
        }
    }

    std::array<int, 2> done{};
    std::set<int> vis;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int x = a[i][j], y = a[j][i];
            if (x == -1)
                continue;

            if (par(x) and (i != j))
            {
                std::cout << "0\n";
                return;
            }

            if (par(x) == 0 and i == j)
            {
                std::cout << "0\n";
                return;
            }

            if (present.count(x % k) and present.count(x % k + k) and x % k != y % k)
            {
                std::cout << "0\n";
                return;
            }

            if (y != -1 and x % k != y % k)
            {
                std::cout  << "0\n";
                return;
            }

            if (vis.count(x % k))
                continue;

            done[par(x)]++;
            vis.emplace(x % k);
        }
    }

    std::array<int, 2> rem{};
    rem[1] = n - done[1];
    rem[0] = k - n - done[0];

    std::cout << comb.fac(rem[0]) * comb.fac(rem[1]) * power<Z>(2, rem[0]) << "\n";
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