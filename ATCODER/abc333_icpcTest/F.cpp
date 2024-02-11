#include <bits/stdc++.h>

#define all(a) begin(a), end(a)

using ll = long long;
using i64 = long long;

void print() {}
template <class Head> void print(Head &head) { std::cout << head << std::endl; }
template <class Head, class... Tail> void print(Head &&head, Tail &&... tail)
{
    std::cout << head << " ";
    print(std::forward<Tail>(tail)...);
}

ll euclid(ll a, ll b, ll &x, ll &y) {
    if (!b) return x = 1, y = 0, a;
    ll d = euclid(b, a % b, y, x);
    return y -= a / b * x, d;
}

constexpr int mod = 998244353;
struct Mod {
    ll x;
    Mod(ll xx) : x(xx) {}
    Mod operator+(Mod b) { return Mod((x + b.x) % mod); }
    Mod operator-(Mod b) { return Mod((x - b.x + mod) % mod); }
    Mod operator*(Mod b) { return Mod((x * b.x) % mod); }
    Mod operator/(Mod b) { return *this * invert(b); }
    Mod invert(Mod a) {
        ll x, y, g = euclid(a.x, mod, x, y);
        assert(g == 1); return Mod((x + mod) % mod);
    }
    Mod operator^(ll e) {
        if (!e) return Mod(1);
        Mod r = *this ^ (e / 2); r = r * r;
        return e & 1 ? *this * r : r;
    }
};

using Z = Mod;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<Z> dp(n + 1, 0);
    dp[0] = 1;

    std::vector<Z> pw2(n + 1, 1);

    auto p = Z(1) / Z(2);
    for (int i = 1; i < n; i++)
    {
        std::vector<Z> ndp(n + 1, 0);
        for (int j = 0; j < i; j++)
            ndp[0] = ndp[0] + dp[j] * (p ^ (i - j + 1));

        for (int j = 0; j < i; j++)
            ndp[j + 1] = (ndp[j] - dp[j] * (Z(p) ^ (i + 1))) * Z(p) + Z(p) * dp[j];

        for (int j = 0; j < i + 1; j++)
            ndp[j] = ndp[j] / (Z(1) - (Z(p) ^ (i + 1)));

        std::swap(dp, ndp);
    }

    for (int i = 1; i <= n; i++)
        std::cout << dp[i - 1].x << " \n"[i == n];
}