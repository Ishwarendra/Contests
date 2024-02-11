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

template <typename T>
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
struct MInt {
    int x;
    MInt() : x{} {}
    MInt(i64 x) : x{norm(x % P)} {}

    int norm(int x)
    {
        if (x < 0)
            x += P;
        if (x >= P)
            x -= P;
        return x;
    }
    constexpr int val() const { return x; }
    explicit constexpr operator int() const { return x; }
    MInt operator-() const
    {
        MInt res;
        res.x = norm(P - x);
        return res;
    }
    MInt inv() const
    {
        assert(x != 0);
        return MInt(inverse(x, P));
    }
    MInt &operator*=(const MInt &rhs)
    {
        x = 1LL * x * rhs.x % P;
        return *this;
    }
    MInt &operator+=(const MInt &rhs)
    {
        x = norm(x + rhs.x);
        return *this;
    }
    MInt &operator-=(const MInt &rhs)
    {
        x = norm(x - rhs.x);
        return *this;
    }
    MInt &operator/=(const MInt &rhs) { return *this *= rhs.inv(); }
    friend MInt operator*(const MInt &lhs, const MInt &rhs)
    {
        MInt res = lhs;
        res *= rhs;
        return res;
    }
    friend MInt operator+(const MInt &lhs, const MInt &rhs)
    {
        MInt res = lhs;
        res += rhs;
        return res;
    }
    friend MInt operator-(const MInt &lhs, const MInt &rhs)
    {
        MInt res = lhs;
        res -= rhs;
        return res;
    }
    friend MInt operator/(const MInt &lhs, const MInt &rhs)
    {
        MInt res = lhs;
        res /= rhs;
        return res;
    }
    friend std::istream &operator>>(std::istream &is, MInt &a)
    {
        i64 v;
        is >> v;
        a = MInt(v);
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const MInt &a) { return os << a.val(); }
    friend constexpr bool operator==(MInt lhs, MInt rhs) { return lhs.val() == rhs.val(); }
    friend constexpr bool operator!=(MInt lhs, MInt rhs) { return lhs.val() != rhs.val(); }
};
 
constexpr int P = 998244353;
using Z = MInt<P>;

template <typename T = int, class F = std::function<T(const T&, const T&)>>
class SparseTable
{
public:
    const int n;
    std::vector<std::vector<T>> mat;
    F func;

    SparseTable(const std::vector<T>& a, const F& f) : func(f), n(std::size(a))
    {
        int max_log = 32 - __builtin_clz(n);
        mat.resize(max_log);
        mat[0] = a;
        for (int j = 1; j < max_log; j++)
        {
            mat[j].resize(n - (1 << j) + 1);
            for (int i = 0; i <= n - (1 << j); i++)
                mat[j][i] = func(mat[j - 1][i], mat[j - 1][i + (1 << (j - 1))]);

        }
    }

    T get(int from, int to) const
    {
        assert(0 <= from && from <= to && to <= n - 1);
        int lg = 32 - __builtin_clz(to - from + 1) - 1;
        return func(mat[lg][from], mat[lg][to - (1 << lg) + 1]);
    }
};

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];

    SparseTable<int> min(a, [&](int x, int y) { return std::min(x, y); });
    SparseTable<int> max(a, [&](int x, int y) { return std::max(x, y); });

    int need = 0;
    for (int i = 0; i < n; i++)
    {
        int add = 0;
        if (i + 1 < n and min.get(i + 1, n - 1) < a[i])
            add |= 1;
        if (i - 1 >= 0 and max.get(0, i - 1) > a[i])
            add |= 1;

        need += add;
    }

    if (need > 0)
        std::cout << power<Z>(2, n - need) << "\n";
    else
        std::cout << power<Z>(2, n) - 1 << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}