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

bool isPrime(int n)
{
    if (n < 2)
        return false;
    for (int x : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37})
    {
        if (n == x)
            return true;
        bool flag = true;
        int r = 1;
        int t = 1;
        while (r <= ((n - 1) >> __builtin_ctz(n - 1)))
        {
            if (r & ((n - 1) >> __builtin_ctz(n - 1)))
                t = (1LL * t * x) % n;
            x = (1LL * x * x) % n;
            r <<= 1;
        }
        if (t == 1 || t == n - 1)
            flag = false;
        for (r = 0; r < __builtin_ctz(n - 1); r++)
        {
            t = (1LL * t * t) % n;
            if (t == n - 1)
                flag = false;
        }
        if (flag)
            return false;
    }
    return true;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    i64 m;
    std::cin >> n >> m;

    // gcd(a[i], i - x) != 1 for any i - x > 1

    Z ans = 0;
    i64 prod = 1;
    Z add = 1;

    for (int i = 1; i <= n; i++)
    {
        if (isPrime(i))
            prod *= i;

        if (m / prod == 0)
            break;  

        add *= (m / prod) % MOD;
        ans += add;     
    }

    Z total = 0;
    m %= MOD;
    for (int i = 1; i <= n; i++)
        total += power<Z>(m, i);

    std::cout << total - ans;

    return 0;
}