#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr int N = 1e6;
constexpr int MOD = 10;

template<class T>
T power(T a, i64 b)
{
    T res = 1;
    for (; b; b /= 2, a = (1LL * a * a) % MOD)
    {
        if (b % 2)
            res = (1LL * res * a) % MOD;
    }
    return res;
}

struct Num
{
    int dig, c2, c5;
    Num(int dig = 0, int c2 = 0, int c5 = 0) : dig(dig), c2(c2), c5(c5) {}
};

Num operator*(Num a, Num b)
{
    a.dig = a.dig * b.dig % MOD;
    a.c2 += b.c2;
    a.c5 += b.c5;
    return a;
}

Num get(int x)
{
    int c2 = 0, c5 = 0;
    while (x % 2 == 0)
        x /= 2, c2++;
    while (x % 5 == 0)
        x /= 5, c5++;

    assert(x % MOD != 0);
    return Num(x % MOD, c2, c5);
}

int get(Num x)
{
    int min = std::min(x.c2, x.c5);
    x.c2 -= min, x.c5 -= min;

    return (x.dig * power(2, x.c2) * power(5, x.c5)) % MOD;
}
    
std::vector<Num> fact(N + 1);

void solve()
{
    int n;
    std::cin >> n;

    auto num = Num(1);
    for (int i = 0; i < n; i++)
    {
        int x;
        std::cin >> x;
        num = num * fact[x]; 
    }

    std::cout << get(num) << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    fact[0] = Num(1);
    for (int i = 1; i <= N; i++)
        fact[i] = fact[i - 1] * get(i);

    int t;
    std::cin >> t;

    while (t--)
        solve();

    return 0;
}