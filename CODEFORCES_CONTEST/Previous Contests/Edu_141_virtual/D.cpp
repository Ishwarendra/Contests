#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr int MOD = 998244353;

// assume -MOD <= x < 2*MOD
int norm(int x)
{
    if (x < 0)
        x += MOD;

    if (x >= MOD)
        x -= MOD;

    return x;
}
template<class T>
T power(T a, int b)
{
    T res = 1;
    for (; b; b /= 2, a *= a)
    {
        if (b % 2)
            res *= a;
    }
    return res;
}
struct Z {
    int x;
    Z(int x = 0) : x(norm(x)) {}
    int val() const {
        return x;
    }
    Z operator-() const {
        return Z(norm(MOD - x));
    }
    Z inv() const {
        assert(x != 0);
        return power(*this, MOD - 2);
    }
    Z &operator*=(const Z &rhs) {
        x = (long long)(x) * rhs.x % MOD;
        return *this;
    }
    Z &operator+=(const Z &rhs) {
        x = norm(x + rhs.x);
        return *this;
    }
    Z &operator-=(const Z &rhs) {
        x = norm(x - rhs.x);
        return *this;
    }
    Z &operator/=(const Z &rhs) {
        return *this *= rhs.inv();
    }
    friend Z operator*(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res *= rhs;
        return res;
    }
    friend Z operator+(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res += rhs;
        return res;
    }
    friend Z operator-(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res -= rhs;
        return res;
    }
    friend Z operator/(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res /= rhs;
        return res;
    }
    friend std::istream &operator>>(std::istream &is, Z &a) {
        int v;
        is >> v;
        a = Z(v);
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const Z &a) {
        return os << a.val();
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    constexpr int N = 300 * 300;

    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    std::vector<Z> dp(N << 1 | 1);

    dp[a[2] - a[1] + N] = 1;
    if (a[1] != 0)
        dp[a[2] + a[1] + N] = 1;

    for (int i = 1; i < n - 2; i++)
    {
        std::vector<Z> ndp(N << 1 | 1);
        
        for (int j = 0; j <= 2 * N; j++)
        {
            // a[i + 1] = j
            if (N + a[i + 2] + (j - N) <= 2 * N)
                ndp[N + a[i + 2] + (j - N)] += dp[j];
            
            if (N + a[i + 2] + (j - N) != N + a[i + 2] - (j - N) and N + a[i + 2] - (j - N) <= 2 * N)
                ndp[N + a[i + 2] - (j - N)] += dp[j];
        }

        std::swap(dp, ndp);
    }

    std::cout << std::accumulate(std::begin(dp), std::end(dp), Z(0));

    return 0;
}