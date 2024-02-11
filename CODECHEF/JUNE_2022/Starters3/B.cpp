#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif

using i64 = long long;

std::set<i64> divisors(i64 x)
{
    std::set<i64> div;

    for (i64 i = 1; i * i <= x; i++)
    {
        if (x % i == 0)
            div.insert(i), div.insert(x / i);
    }

    div.erase(x);
    return div;
}


void solve()
{
    i64 n;
    std::cin >> n;

    auto div = divisors(n);
    i64 cnt = 0;
    // i64 LIMIT = *div.rbegin();

    for (auto i : div)
    {
        if (std::gcd(i, n - i) + std::lcm(i, n - i) == n)
        {
            print(i, n - i)
            cnt++;
        }
    }

    std::cout << cnt * 2LL - (n % 2 == 0) << "\n";
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