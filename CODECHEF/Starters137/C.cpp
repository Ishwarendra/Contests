#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;
using i128 = __int128;
using u128 = __uint128_t;

std::ostream &operator<<(std::ostream &os, i128 x)
{
    std::string s;
    bool neg = false;
    if (x < 0)
        neg = true, x = -x;
    if (x == 0)
        s = "0";

    while (x)
    {
        s += '0' + x % 10;
        x /= 10;
    }

    if (neg)
        s += '-';
    s = std::string(std::rbegin(s), std::rend(s));
    return os << s;
}

std::istream& operator >> (std::istream &is, i128 &T)
{
    static char buffer[64];
    is >> buffer;
    size_t len = strlen(buffer), index = 0;
    T = 0;
    int mul = 1;

    if (buffer[index] == '-')
        ++index, mul *= -1;
    for (; index < len; ++index)
        T = T * 10 + static_cast<int>(buffer[index] - '0');
    T *= mul;

    return is;
}

i128 apSum(i64 a)
{
    if (a < 0)
        return 0;
    return i128(a) * (a + 1) / 2;
}

i128 apSum(i64 a, i64 b)
{
    if (b < a)
        return 0;
    return apSum(b) - apSum(a - 1);
}

void solve()
{
    i64 n, a, b;
    std::cin >> n >> a >> b;

    if (a == b)
    {
        std::cout << n / a << "\n";
        return;
    }
    
    if (a < b)
        std::swap(a, b);

    if (n <= a)
    {
        if (n == a)
            std::cout << "2\n";
        else if (n == b)
            std::cout << "1\n";
        else
            std::cout << "0\n";
        return;
    }

    i64 max = n / a;
    i128 ans = apSum(2, max + 1) - apSum(1, max - a + 1);

    if (i128(b) * (max + 1) > i128(a) * max)
        ans += std::max<i128>(0, n - i128(b) * (max + 1) + 1);
    else
        ans += std::max<i128>(0, n - i128(a) * max);
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