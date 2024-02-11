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

void solve()
{
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n), inv(n + 1);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    for (int i = 1; i <= n; i++)
        inv[i] = Z(i).inv().val();

    std::string s;
    std::cin >> s;

    std::vector dp(n, std::vector<Z>(n));
    dp[0][n - 1] = 1;

    for (int K = 0; K < k; K++)
    {
        std::vector ndp(n, std::vector<Z>(n));

        if (s[K] == 'L')
        {
            for (int i = 0; i < n; i++)
            {
                Z sum = 0;
                for (int j = n - 1; j > i; j--)
                {
                    ndp[i][j] = sum;
                    sum += dp[i][j] * inv[j - i];
                }

                ndp[i][i] = sum + dp[i][i];
            }
        }
        else
        {
            for (int j = 0; j < n; j++)
            {
                Z sum = 0;
                for (int i = 0; i < j; i++)
                {
                    ndp[i][j] = sum;
                    sum += dp[i][j] * inv[j - i];
                }

                ndp[j][j] = sum + dp[j][j];
            }
        }

        std::swap(ndp, dp);
    }

    std::vector<Z> p(n + 1);
    for (int i = 0; i < n; i++)
        p[i + 1] = p[i] + a[i];

    Z ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            Z sum = p[j + 1] - p[i];
            ans += sum * dp[i][j];
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