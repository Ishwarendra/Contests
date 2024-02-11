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
    i64 n;
    std::cin >> n;

    if (n <= 4)
    {
        std::cout << (n == 1 ? "0\n" : "1\n");
        return;
    }

    auto binSearch = [&](auto good, i64 &ans)
    {
        i64 left = 0, right = 2e9;
        while (left <= right)
        {
            i64 mid = (left + right) >> 1;
            if (good(mid))
                ans = mid, right = mid - 1;
            else
                left = mid + 1;
        }

        return ans;
    };

    auto good1 = [&](i64 mid)
    {
        return 4 * mid * mid >= n;
    };

    auto good2 = [&](i64 mid)
    {
        return 4 * mid * (mid + 1) >= n - 1;
    };

    i64 ans1 = 0, ans2 = 0;
    binSearch(good1, ans1); 
    binSearch(good2, ans2);

    ans1 = 2 * ans1 - 1;
    ans2 = 2 * ans2;
    std::cout << std::min(ans1, ans2) << "\n";
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