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
    
    std::string s;
    std::cin >> s;

    int i = std::size(s);
    i--;

    while (i >= 0)
    {
        if (s[i] == 'a')
        {
            std::cout << i + 1 << "\n";
            return 0;
        }
        i--;
    }

    std::cout << i << "\n";
    
    return 0;
}