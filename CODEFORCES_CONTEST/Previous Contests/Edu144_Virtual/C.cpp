#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

template<class T>
T power(T a, i64 b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
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
    int val() const { return x; }
    MInt operator-() const
    {
        MInt res;
        res.x = norm(P - x);
        return res;
    }
    MInt inv() const
    {
        assert(x != 0);
        return power(*this, P - 2);
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
};

constexpr int P = 998244353;
using Z = MInt<P>;

void solve()
{
    int l, r;
    std::cin >> l >> r;

    int max = 0;
    while (l * (1LL << max) <= r)
        max++;

    if (max == 1)
    {
        std::cout << max << " " << r - l + 1 << "\n";
        return;
    }

    Z ans = 0;
    i64 prod = 1LL << (max - 2);

    // for (int start = l; start <= r; start++)
    // {
    //     if (start * prod * 2 > r)
    //         break;

    //     int three = 0;

    //     if (start * prod * 3 <= r)
    //         three = 1;

    //     // print(start, three, l * (1LL << (max - 2)))
    //     if (!three)
    //         ans += 1;
    //     else
    //         ans += max;
    // }
    if (r / prod / 2 - l + 1 > 0)
        ans += r / prod / 2 - l + 1;

    if (r / prod / 3 - l + 1 > 0)
        ans += Z(max - 1) * (r / prod / 3 - l + 1);

    std::cout << max << ' ' << ans << "\n";
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