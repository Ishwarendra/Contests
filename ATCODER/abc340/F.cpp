#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i128 = __int128;
using u128 = __uint128_t;
using i64 = i128;

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

i64 gcd(i64 a, i64 b, i64 &x, i64 &y) 
{
    if (b == 0) 
    {
        x = 1;
        y = 0;
        return a;
    }

    i64 x1, y1;
    i64 d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

i128 abs_(i128 x) { return x > 0 ? x : -x; }

bool find_any_solution(i64 a, i64 b, i64 c, i64 &x0, i64 &y0, i64 &g) {
    g = gcd(abs_(a), abs_(b), x0, y0);
    if (c % g) {
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    i64 x, y;
    std::cin >> x >> y;

    i64 a, b, g;
    if (find_any_solution(x, -y, 2LL, a, b, g))
        std::cout << b << " " << a << "\n";
    else if (find_any_solution(x, -y, -2LL, a, b, g))
        std::cout << b << " " << a << "\n";
    else
        std::cout << "-1\n";
    
    return 0;
}