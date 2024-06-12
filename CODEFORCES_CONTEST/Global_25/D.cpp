#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;
using i128 = __int128;

std::string to_string(i128 x)
{
    std::string ans;
    while (x)
    {
        ans += char('0' + (x % 10));
        x /= 10;
    }

    std::reverse(std::begin(ans), std::end(ans));
    return ans;
}

void solve()
{
    i64 n, k;
    std::cin >> n >> k;

    if (n % k == 0)
        std::cout << "YES\n1\n" << n / k << '\n';
    else
    {
        i128 c = n - k + 1;

        if (c <= 0)
        {
            std::cout << "NO\n";
            return;
        }

        i128 b = n / c;
        n -= b * c;
        k -= b;
        k -= n;

        if (k == 0)
            std::cout << "YES\n2\n" << to_string(c) << " 1\n";
        else
            std::cout << "NO\n";
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