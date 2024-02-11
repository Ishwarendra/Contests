#include <bits/stdc++.h>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

using i64 = long long;

template<class T>
T power(T a, int b) {
    T res = 1;
    for (; b; b /= 2, a *= a) 
    {
        if (b % 2)
            res *= a;
    }

    return res;
} 

void solve()
{
    i64 a, m;
    std::cin >> a >> m;

    i64 g = std::gcd(a, m);

    a /= g, m /= g;

    auto pf = [&a](i64 x)
    {
        std::map<i64, int> m;

        for (i64 i = 2; i * i <= x; i++)
        {
            while (x % i == 0)
                x /= i, m[i]++;
        }

        if (x > 1)
            m[x]++;

        return m;
    };

    auto p = pf(m);
    i64 phi = 1;

    for (auto [prime, alpha] : p)
    {
        assert(alpha - 1 >= 0);
        phi *= power(prime, alpha) - power(prime, alpha - 1);
    }

    print(phi, p)
    std::cout << phi << "\n";
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