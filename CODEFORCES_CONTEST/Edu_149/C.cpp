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

    auto check = [&](int i)
    {
        if (i - 1 >= 0 and s[i - 1] == '0')
            return true;
        if (i + 1 < n and s[i + 1] == '0')
            return true;

        return false;
    };

    if (s[0] == '?')
        s[0] = '0';
    for (int i = 1; i < n; i++)  
    {
        if (s[i] != '?')
            continue;
        
        if (check(i))
            s[i] = '0';
        else
            s[i] = '1';
    }

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