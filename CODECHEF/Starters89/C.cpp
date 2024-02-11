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

void solve()
{
    i128 n, m, k;
    std::cin >> n >> m >> k;

    i128 a = 0, b = 0;
    for (int i = 0; i < n; i++)  
    {
        int x;
        std::cin >> x;
        a += x;
    }

    for (int i = 0; i < m; i++)
    {
        int x;
        std::cin >> x;
        b += x;
    }

    int op = 0;
    while (m * a <= n * b)
    {
        i128 d1 = m * k - b;
        i128 d2 = a - n;
        if (op > 1e6)
        {
            std::cout << "-1\n";
            return;
        }

        op++;
        if (d1 > d2)
            a += k, n++;
        else
            b += 1, m++;
    }

    std::cout << op << "\n";
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