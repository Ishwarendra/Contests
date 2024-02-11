#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    std::string s;
    std::cin >> n >> s;

    int cnt = std::count(std::begin(s), std::end(s), '0');
    if (cnt == n or cnt == 0 or std::size(s) <= 2)
    {
        std::cout << s << "\n";
        return;
    }

    int fix = 1;

    for (int i = 1; i < n - 1; i++)
    {
        if (s[i - 1] == s[i + 1])
        {
            if (s[i] == '1')
                fix = 0;
        }
        else if (s[i] == '0')
            fix = 0;
    } 

    if (fix)
    {
        std::cout << s << "\n";
        return;
    }

    for (int i = 1; i < n - 1; i++) 
        s[i] = '1';

    if (s[0] == '1' and s.back() != '0')
        s[1] = '0';

    std::cout << s << "\n";
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