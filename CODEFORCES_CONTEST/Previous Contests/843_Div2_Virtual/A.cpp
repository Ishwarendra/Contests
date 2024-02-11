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
    int n = std::size(s);

    if (std::size(std::set(std::begin(s), std::end(s))) == 1)
    {
        char ch = s[0];
        std::cout << ch << " " << std::string(n - 2, ch) << " " << ch << "\n";
    }
    else if (s[0] == 'a')
    {
        int pos = 0;
        while (pos < n - 2 and s[pos] != 'b')
        {
            std::cout << 'a';
            pos++;
        }
        std::cout << ' ';

        while (pos < n - 1)
            std::cout << s[pos++];
        std::cout << ' ';

        std::cout << s[pos] << "\n";
    }
    else 
    {
        std::cout << s[0] << " " << s[1] << " ";
        int pos = 2;
        while (pos < n)
            std::cout << s[pos++];
        std::cout << "\n";
    }
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