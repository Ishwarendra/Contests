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

constexpr int P = 1e9 + 7;
using Z = MInt<P>;

constexpr int N = 3e3 + 10;

std::vector dp(N, std::vector<Z>(6));

void solve()
{
    int n;
    std::cin >> n;

    Z ans = 0;
    for (int i = 0; i < 5; i++)
        ans += dp[n][i];

    std::cout << ans << '\n';
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    dp[0][0] = 1;
    {
        // for (int i = 1; i < N; i++)
        // {
        //     for (int j = 0; j < 5; j++)
        //     {
        //         if (j == 0)
        //         {
        //             for (int k = 0; k < 5; k++)
        //             {
        //                 if (k != 2)
        //                     dp[i][j] += 2 * dp[i - 1][k];
        //                 else
        //                     dp[i][j] += dp[i - 1][k];
        //             }
        //         }
        //         else if (j == 2)
        //             dp[i][j] += dp[i - 1][j - 1] + dp[i - 1][j];
        //         else
        //             dp[i][j] += dp[i - 1][j - 1];
        //     }
        // }
    }

    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (j == 0)
            {
                for (int k = 0; k < 5; k++)
                    dp[i][j] += 2 * dp[i - 1][k];
                dp[i][j] -= dp[i - 1][2];
                dp[i][j] -= dp[i - 1][3];
            }
            else if (j == 2) {
                dp[i][j] += (dp[i - 1][j - 1] + dp[i - 1][j]);
            }
            else
                dp[i][j] += dp[i - 1][j - 1];
            if (j == 1) {
                dp[i][j] += dp[i - 1][3];
            }
        }
    }

    int t = 1;
    std::cin >> t;

    while (t--)
        solve();

    return 0;
}