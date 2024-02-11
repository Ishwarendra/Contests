#include<bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h>
#else
#define trace(...) 1;
#define print(...) 1;
#endif

const double pi = std::acos(-1);

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cout << std::fixed;
    std::cout << std::setprecision(17);

    double a, b, d;
    std::cin >> a >> b >> d;

    d = pi * d / 180;
    double c = std::cos(d), s = std::sin(d);
    print(c, s)

    std::cout << a * c + b * s << " " << b * c + a * s << "\n";

    return 0;
}