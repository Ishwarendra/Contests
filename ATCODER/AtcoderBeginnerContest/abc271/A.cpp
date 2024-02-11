#include <bits/stdc++.h>

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
    
    int n;
    std::cin >> n;

    std::string ans;
    while (n)
    {
        int x = n % 16;
        n /= 16;
        char ch;
        if (x >= 10)
            ch = 'A' + (x - 10);
        else
            ch = std::to_string(x)[0];

        ans = ch + ans; 
    }

    if (ans.size() == 1)
        ans = '0' + ans;
    if (ans.size() == 0)
        ans = "00";

    std::cout << ans;
    
    return 0;
}