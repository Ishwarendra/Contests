#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

using i64 = long long;

constexpr int MOD = 1e9 + 7;

// assume -MOD <= x < 2*MOD
int norm(int x) {
    if (x < 0) {
        x += MOD;
    }
    if (x >= MOD) {
        x -= MOD;
    }
    return x;
}
template<class T>
T power(T a, int b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
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


void solve()
{
    int n;
    std::cin >> n;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) 
        std::cin >> a[i];

    std::vector<int> b = a;
    auto even = [&](int x)
    {
        return x % 2 == 0;
    };

    for (int i = 1; i < n - 1; i++)
    {
        int &a_1 = b[i - 1];
        int &a_2 = b[i]; 
        int &a_3 = b[i + 1];

        if (std::gcd(a_1, a_2) == 1 and std::gcd(a_2, a_3) == 1)
            continue;
        int cnt = even(a_1) + even(a_2) + even(a_3);

        if (even(a_1) and even(a_2) and even(a_3))
            a_2--;
        else if (!even(a_1) and !even(a_2) and !even(a_3))
            a_2++;
        else if (even(a_1) and even(a_2))
            a_1--;
        else if (even(a_2) and even(a_3))
            a_3--;
        else if (!even(a_1) and !even(a_2))
            a_1--;
        else if (!even(a_2) and !even(a_3))
            a_3--;
    }

    if (n == 2 and std::gcd(b[0], b[1]) != 1)
    {
        if (even(b[0]) and even(b[1]))
            b[0]--;
        else if (!even(b[0]) and !even(b[1]))
            b[1]++;
        else
        {
            if (b[0] & 1)
                b[1]++;
            else
                b[0]++;
        }
    }

    Z ans = 0;
    print(b)
    for (int i = 0; i < n; ++i)
        ans += power(Z(2), abs(a[i] - b[i]));

    // for (int i = 0; i < n - 1; ++i)
    //     assert(std::gcd(b[i], b[i + 1]) == 1);

    std::cout << ans << "\n";
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