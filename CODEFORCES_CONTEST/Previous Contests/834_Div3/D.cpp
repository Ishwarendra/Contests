#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

template<class T, class G>
T power(T a, G b) 
{
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
    int n, m;
    std::cin >> n >> m;
    
    auto powers = [&](int n, int x)
    {
        int ans = 0;
        while (n % x == 0)
            n /= x, ans++;

        return ans;
    };   

    int two = powers(n, 2), five = powers(n, 5);
    i64 num = 1;

    if (two < five)
    {
        while (num <= m and two != five)
            num *= 2LL, two++;

        if (num > m)
            num /= 2;
    }
    else if (five < two)
    {
        while (num <= m and two != five)
            num *= 5LL, five++;

        if (num > m)
            num /= 5;
    }

    while (num <= m)
        num *= 10LL;
    num /= 10LL;

    for (int i = 100; i >= 1; i--)
    {
        if (num * i <= m)
        {
            num *= i;
            break;
        }
    }

    std::cout << num * n << "\n";
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