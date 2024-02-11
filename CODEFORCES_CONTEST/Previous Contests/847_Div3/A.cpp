#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    std::string s;
    std::cin >> s;

    std::string actual = "31415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679";

    int n = std::size(s);
    for (int i = 0; i < n; i++)
    {
        if (s[i] != actual[i])
        {
            std::cout << i << "\n";
            return;
        }
    }

    std::cout << n << "\n";
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