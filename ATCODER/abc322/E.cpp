#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

template<class T>
T power(T a, int b) 
{
    T res = 1;
    for (; b; b /= 2, a *= a) 
    {
        if (b % 2) 
            res *= a;
    }
    return res;
} 

constexpr i64 inf = 1e18;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, k, p;
    std::cin >> n >> k >> p;

    std::vector<int> c(n);
    std::vector a(n, std::vector(k, 0));
    
    for (int i = 0; i < n; i++)    
    {
        std::cin >> c[i];
        for (int j = 0; j < k; j++)
            std::cin >> a[i][j];
    }

    auto numToArray = [&](int x)
    {
        std::vector<int> num(k);
        int id = k - 1;
        while (x)
        {
            num[id--] = x % p;
            x /= p;
        }

        return num;
    };

    auto arrayToNum = [&](std::vector<int> num)
    {
        int x = 0;
        for (int i = 0; i < std::size(num); i++)
            x = x * p + num[i];
        return x;
    };

    auto chmin = [&](auto &x, auto y)
    {
        if (x > y)
            x = y;
    };

    p++;
    const int M = power(p, k);
    std::vector<i64> dp(M, inf);
    dp[0] = 0;

    for (int i = 0; i < n; i++)
    {
        std::vector<i64> ndp(M, inf);
        for (int j = 0; j < M; j++)
        {
            auto num = numToArray(j);

            for (int id = 0; int x : a[i])
            {
                num[id] = std::min(p - 1, num[id] + x);
                id++;
            }
            
            chmin(ndp[arrayToNum(num)], dp[j] + c[i]);
            chmin(ndp[j], dp[j]);
        }

        std::swap(dp, ndp);
    }

    std::cout << (dp.back() == inf ? -1 : dp.back());
    
    return 0;
}