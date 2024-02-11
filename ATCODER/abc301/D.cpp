#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    auto decimal = [&](std::string s, int max = 0)
    {
        i64 ans = 0;
        int n = std::size(s);
        for (int i = 0; i < n; i++)
        {
            if (s[i] != '?')
                ans = ans * 2 + s[i] - '0';
            else
                ans = ans * 2 + max;
        }

        return ans;
    };

    std::string s;
    i64 x;
    std::cin >> s >> x;

    int n = std::size(s);
    i64 ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] != '?')
            ans = ans * 2 + s[i] - '0';
        else
        {
            s[i] = '1';
            i64 dec = decimal(s, 0);
            if (dec > x)
                s[i] = '0';

            ans = ans * 2 + s[i] - '0';
        }
    }

    std::cout << (ans <= x ? ans : -1LL);
    
    return 0;
}