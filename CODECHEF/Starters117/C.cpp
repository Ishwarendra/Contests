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

Z sum(int n) { return Z(n) * (n + 1) / 2; }
Z sum(int l, int r) { return sum(r) - sum(l - 1); }

void solve()
{
    int n, m;
    std::cin >> n >> m;

    int k = std::max(n / 2, m / 2);
    auto get = [&](int n, int m) -> Z
    {
        auto good = [&](int mid)
        {
            int x = (n + 1) / 2, y = (m + 1) / 2 + mid;
            if (y > m)
                return false;

            int max = std::max({std::abs(x - 1), std::abs(n - x), std::abs(y - 1), std::abs(m - y)});
            return max <= k;
        };

        Z ans = (n + 1) / 2;
        int left = 0, right = (m + 1) / 2;
        int x = -1;

        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (good(mid))
                x = mid, left = mid + 1;
            else
                right = mid - 1;
        }

        if (x == -1)
            return Z(0);

        auto good2 = [&](int mid)
        {
            int x = (n + 1) / 2, y = (m + 1) / 2 - mid;
            if (y <= 0)
                return false;

            int max = std::max({std::abs(x - 1), std::abs(n - x), std::abs(y - 1), std::abs(m - y)});
            return max <= k;
        };

        left = 0, right = (m + 1) / 2;
        int y = -1;

        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (good2(mid))
                y = mid, left = mid + 1;
            else
                right = mid - 1;
        }

        ans *= sum((m + 1) / 2 - y, (m + 1) / 2 + x);
        if (n % 2 == 0)
        {
            Z add = (n + 1) / 2 + 1;
            if (add.x <= n)
            {
                add *= sum((m + 1) / 2 - y, (m + 1) / 2 + x);
                ans += add;
            }
        }

        return ans;
    };

    Z ans = 0;
    if (n / 2 == k)
        ans += get(n, m);
    if (m / 2 == k)
        ans += get(m, n);

    if (n / 2 == k and m / 2 == k)
    {
        int x = (n + 1) / 2, y = (m + 1) / 2;
        for (int i = 0; i < (n % 2 ? 1 : 2); i++)
        {
            for (int j = 0; j < (m % 2 ? 1 : 2); j++)
                ans -= Z(x + i) * (y + j);
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