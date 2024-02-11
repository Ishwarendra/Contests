#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr int inf = 1e9;

template<class T>
T power(T a, int b) 
{
    T res = 1;
    for (; b; b /= 2, a *= a) 
    {
        if (a > inf)
            return inf;

        if (b % 2) 
            res *= a;

        if (res > inf)
            return inf;
    }
    return res;
} 

void solve()
{
    int n;
    std::cin >> n;

    auto check = [&](int k)
    {
        auto good = [&](int mid)
        {
            i64 sum = power<i64>(k, mid);
            if (sum > n)
                return 1;

            sum = power<i64>(k, mid + 1) - 1;
            sum /= k - 1;

            if (sum > n)
                return 1;
            else if (sum < n)
                return -1;
            return 0;
        };

        int left = 1, right = 20;
        while (left <= right)
        {
            int mid = (left + right) >> 1;
            if (good(mid) == 0)
                return true;
            else if (good(mid) == -1)
                left = mid + 1;
            else
                right = mid - 1;
        }   

        return false;
    };

    for (int k = 2; k < int(1e3) + 50; k++)  
    {
        if (1 + k + k * k <= n and check(k))
        {
            print(k)
            std::cout << "YES\n";
            return;
        }
    }

    std::cout << "NO\n";
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