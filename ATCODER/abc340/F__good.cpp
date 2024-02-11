#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

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

bool find_any_solution(i64 a, i64 b, i64 c, i64 &x0, i64 &y0, i64 &g) {
    g = gcd(abs(a), abs(b), x0, y0);
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
    if (find_any_solution(x, y, 2LL, a, b, g))
    {
        std::cout << b << " " << a << "\n";
    }
    else if (find_any_solution(x, y, -2LL, a, b, g))
    {
        std::cout << b << " " << a << "\n";
    }
    else
        std::cout << "-1\n";
    
    return 0;
}