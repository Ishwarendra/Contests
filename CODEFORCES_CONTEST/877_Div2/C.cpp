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


void solve()
{
    int n, m;
    std::cin >> n >> m;

    std::vector a(n, std::vector(m, 0));
    int cur = 1;
    for (int i = 0; i < n; i++)  
    {
        for (int j = 0; j < m; j++)
            a[i][j] = cur++;
    }

    if (m % 2)
    {
        /*
           1 8 15 22 29
           15 1 22 8 29
        */
        std::vector<std::vector<int>> b(n);
        int pos = 1;
        for (int i = 0; i < n / 2; i++)
            b[pos] = a[i], pos += 2;
        pos = 0;
        for (int i = n / 2; i < n; i++)
            b[pos] = a[i], pos += 2;
        a = b;        
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            std::cout << a[i][j] << " \n"[j == m - 1];
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}