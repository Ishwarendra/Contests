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

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, a, b, p, q;
    std::cin >> n >> a >> b >> p >> q;

    std::vector dp(n + 1, std::vector(n + 1, std::array<Z, 2>{}));
    dp[a][b][0] = 1;

    for (int i = a; i < n; i++)
    {
        for (int j = b; j < n; j++)
        {
            for (int x = 1; x <= p; x++)   
                dp[std::min(n, i + x)][j][1] += dp[i][j][0] / p;
            for (int x = 1; x <= q; x++)
                dp[i][std::min(n, j + x)][0] += dp[i][j][1] / q;
        }
    }

    Z ans = 0;

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //         print(i, j, dp[i][j][0].x, dp[i][j][1].x)
    // }

    for (int i = 1; i < n; i++)
        ans += dp[n][i][1];

    std::cout << ans;
    
    return 0;
}