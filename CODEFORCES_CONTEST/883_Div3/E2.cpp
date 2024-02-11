#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;
using i128 = __int128;
using u128 = __uint128_t;

std::ostream &operator<<(std::ostream &os, i128 n) 
{
    std::string s;
    while (n) 
    {
        s += '0' + n % 10;
        n /= 10;
    }
    std::reverse(std::begin(s), std::end(s));
    return os << s;
}

std::istream& operator >> (std::istream &is, i128 &T) 
{
    static char buffer[64];
    is >> buffer; 
    size_t len = strlen(buffer), index = 0; 
    T = 0; 
    int mul = 1;

    if (buffer[index] == '-') 
        ++index, mul *= -1; 
    for (; index < len; ++index) 
        T = T * 10 + static_cast<int>(buffer[index] - '0'); 
    T *= mul; 

    return is;
}

constexpr i128 inf = 1e20;

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

std::vector<i128> limit(63);

void solve()
{
    i64 n;
    std::cin >> n;

    for (int t = 3; t <= 62; t++)  
    {
        auto good = [&](i128 k)
        {
            i128 lhs = k * n - power(k, t);
            i128 rhs = n - 1; 

            if (lhs > rhs)
                return -1;
            else if (lhs < rhs)
                return 1;
            else
                return 0;
        };

        i128 left = 2, right = limit[t - 1];
        i128 ans = -1;

        while (left <= right)
        {
            auto mid = (left + right) / 2;
            if (good(mid) == 0)
            {
                ans = mid;
                break;
            }
            else if (good(mid) == -1)
                left = mid + 1;
            else
                right = mid - 1;
        }

        if (ans != -1)
        {
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

    limit[1] = 1e9;
    for (int i = 2; i <= 62; i++)
    {
        i128 left = 2, right = limit[i - 1];
        i128 ans = 1;
        while (left <= right)
        {
            i128 mid = (left + right) / 2;
            if (power(mid, i) < inf)
                ans = mid, left = mid + 1;
            else
                right = mid - 1;
        }

        limit[i] = ans;
    }

    int t;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}