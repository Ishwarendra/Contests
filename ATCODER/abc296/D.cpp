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
    while (n) {
        s += '0' + n % 10;
        n /= 10;
    }
    std::reverse(s.begin(), s.end());
    return os << s;
}

std::istream& operator >> (std::istream& is, i128& T) 
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

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    i128 n, m;
    i64 m_;
    std::cin >> n >> m_;
    m = m_;

    if (m > n * n)
    {
        std::cout << "-1\n";
        return 0;
    }

    i128 limit = std::sqrt(m_) + 10;

    i128 ans = -1;
    for (int a = 1; a <= std::min(limit, n); a++)
    {
        i128 b = (m + a - 1) / a;
        if (a <= n and b <= n)
        {
            if (ans == -1)
                ans = a * b;
            else
                ans = std::min(ans, a * b);
        }
    }

    std::cout << ans;

    return 0;
}