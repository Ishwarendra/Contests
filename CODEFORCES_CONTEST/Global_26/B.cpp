#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    std::string s;
    std::cin >> s;
    
    int n = std::size(s);
    std::string a(n - 1, '0'), b(n - 1, '0');
    int carry = 0;
    for (int i = n - 1; i > 0; i--)
    {
        int need = s[i] - '0' - carry + 10;
        for (int d = 5; d <= 9; d++)
        {
            int d2 = need - d;
            if (5 <= d2 and d2 <= 9)    
            {
                a[i - 1] = d + '0';
                b[i - 1] = d2 + '0';
                break;
            }
        }
        
        carry = 1;
    }  
    
    auto count = [&](std::string &s, char ch)
    {
        return std::count(std::begin(s), std::end(s), ch);
    };

    if (s.front() != '1' or count(a, '0') or count(b, '0'))
        std::cout << "NO\n";
    else
        std::cout << "YES\n";
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