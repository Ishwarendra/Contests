#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

i64 gcd(i64 a, i64 b, i64& x, i64& y) 
{
    if (b == 0) {
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

bool find_any_solution(i64 a, i64 b, i64 c, i64 &x0, i64 &y0, i64 &g) 
{
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

void shift_solution(i64 & x, i64 & y, i64 a, i64 b, i64 cnt) {
    x += cnt * b;
    y -= cnt * a;
}

const int inf = 1e9;

std::array<i64, 2> find_all(i64 a, i64 b, i64 c) 
{
    i64 x, y, g;

    i64 minx = 0, miny = 0;
    i64 maxx = inf, maxy = inf;
    if (!find_any_solution(a, b, c, x, y, g))
        return {-1, -1};

    a /= g;
    b /= g;

    i64 sign_a = a > 0 ? +1 : -1;
    i64 sign_b = b > 0 ? +1 : -1;

    shift_solution(x, y, a, b, (minx - x) / b);
    if (x < minx)
        shift_solution(x, y, a, b, sign_b);
    if (x > maxx)
        return {-1, -1};
    i64 lx1 = x;

    shift_solution(x, y, a, b, (maxx - x) / b);
    if (x > maxx)
        shift_solution(x, y, a, b, -sign_b);
    i64 rx1 = x;

    shift_solution(x, y, a, b, -(miny - y) / a);
    if (y < miny)
        shift_solution(x, y, a, b, -sign_a);
    if (y > maxy)
        return {-1, -1};
    i64 lx2 = x;

    shift_solution(x, y, a, b, -(maxy - y) / a);
    if (y > maxy)
        shift_solution(x, y, a, b, sign_a);
    i64 rx2 = x;

    if (lx2 > rx2)
        std::swap(lx2, rx2);
    i64 lx = std::max(lx1, lx2);
    i64 rx = std::min(rx1, rx2);

    rx = (c - a * lx) / b;
    return {lx, rx};   
}

void solve()
{
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;

    if ((a + 1) % b == (c + 1) % d)
        std::cout << "1\n";
    else if (a % b == 0)
        std::cout << std::lcm<i64>(b, d) << "\n";
    else
    {
        i64 r1 = -(a % b);
        r1 = (r1 + b) % b;

        i64 r2 = -(c % d);
        r2 = (r2 + d) % d;

        auto [x, y] = find_all(b, -d, r2 - r1);
        assert(x != -1);
        std::cout << r1 + x * b << "\n";
    }
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