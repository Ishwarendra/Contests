#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

bool isPrime(int n)
{
    if (n < 2)
        return false; 
    for (int x : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37})
    {
        if (n == x)
            return true;
        bool flag = true;
        int r = 1;
        int t = 1;
        while (r <= ((n - 1) >> __builtin_ctz(n - 1)))
        {
            if (r & ((n - 1) >> __builtin_ctz(n - 1)))
                t = (1LL * t * x) % n;
            x = (1LL * x * x) % n;
            r <<= 1;
        }
        if (t == 1 || t == n - 1)
            flag = false;
        for (r = 0; r < __builtin_ctz(n - 1); r++)
        {
            t = (1LL * t * t) % n;
            if (t == n - 1)
                flag = false;
        }
        if (flag)
            return false;
    }
    return true;
}


int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum = 0, prod = 1;
            for (int k = i; k <= j; k++)
                sum += a[k], prod *= a[k];

            if (isPrime(sum * prod))
                ans++;
        }
    }
    
    std::cout << ans;
    return 0;
}