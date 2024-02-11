#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

auto sq(auto x)
{
    return x * x;
}

template<typename T = int, typename G = double>
G sqroot(T x, double eps = 1e-7)
{
    x = std::abs(x);
    if (x > 1e10)
        eps = 1e-4;

    G left = 0, right = x;

    while (right - left > eps)
    {
        G mid = std::midpoint(left, right);
        if (mid >= x / mid)
            right = mid;
        else
            left = mid;
    }

    return left + (right - left) / 2;
}

auto dist(auto x1, auto y1, auto x2, auto y2)
{
    return sqroot(sq(x1 - x2) + sq(y1 - y2));
}

auto sgn(int x)
{
    return x < 0 ? -1 : 1;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    long double R, x1, y1, x2, y2;
    std::cin >> R >> x1 >> y1 >> x2 >> y2;

    if (dist(x1, y1, x2, y2) > R)
    {
        std::cout << x1 << " " << y1 << " " << R << "\n";
        std::exit(0);
    }

    std::array<long double, 2> shift {x1, y1};

    x2 -= x1, y2 -= y1;
    x1 = y1 = 0;

    constexpr long double inf = 1e18;
    auto getRoots = [&](auto a, auto b, auto c)
    {
        auto D = std::sqrt(b * b - 4 * a * c);
        std::array<long double, 2> roots;

        if (a == 0)
            roots = {inf, -inf};
        else if (a == inf)
            roots = {0, 0};
        else
        {
            roots[0] = (-b + D) / 2 / a;
            roots[1] = (-b - D) / 2 / a;
        }

        return roots; 
    };  

    long double m = (x2 == x1 ? inf : (y2 - y1) / (x2 - x1));
    long double c = y1 - m * x1;

    auto X = getRoots(1 + m * m, 2 * m * c, c * c - R * R);
    
    auto getY = [&](auto x)
    {
        return sqroot(R * R - x * x);
    };  

    std::array<long double, 2> Y {-R, R};
    if (x1 != x2)
        Y = {getY(X[0]), getY(X[1])};

    if (dist(X[1], Y[1], x2, y2) > dist(X[0], Y[0], x2, y2))
        std::swap(X[0], X[1]), std::swap(Y[0], Y[1]);
    
    long double r1 = dist(X[0], Y[0], x2, y2) / 2;
    long double r2 = dist(X[0], Y[0] * -1, x2, y2) / 2;
    long double r = r1;
    if (r2 > r1)
        r = r2, Y[0] *= -1;
    
    long double x = (X[0] + x2) / 2;
    long double y = (Y[0] + y2) / 2;
    std::cout << std::fixed << std::setprecision(8);
    std::cout << (x + shift[0]) << " " << (y + shift[1]) << " " << r;
    
    return 0;
}