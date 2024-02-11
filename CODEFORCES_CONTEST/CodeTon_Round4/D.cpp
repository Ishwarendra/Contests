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

i128 get(i128 h, i128 a, i128 b)
{
    if (a >= h)
        return 1;

    if (a - b <= 0)
        return -1;

    i128 x = (h - a + a - b - 1) / (a- b);
    return x + 1; 
};

void solve()
{
    int q;
    std::cin >> q;

    i128 max = std::numeric_limits<i128>::max(), min = 0;

    while (q--)  
    {
        int t;
        std::cin >> t;

        if (t == 1)
        {
            int a, b, d;
            std::cin >> a >> b >> d;

            i128 x = 1LL * (a - b) * (d - 1);
            i128 maxx = x + a, minx = 1LL * (a - b) * (d - 2) + a + 1;

            if (d == 1)
                maxx = a, minx = 1;

            if (maxx < min or minx > max or minx > maxx)
                std::cout << "0 ";
            else
            {
                std::cout << "1 ";
                max = std::min(max, maxx);
                min = std::max(min, minx);
            }
            print(max, min)
        }
        else
        {
            int a, b;
            std::cin >> a >> b;

            i128 gmin = get(min, a, b);
            i128 gmax = get(max, a, b);
            if (gmin == gmax)
                std::cout << gmin << " ";
            else
                std::cout << "-1 ";
        }
    }

    std::cout << "\n";
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