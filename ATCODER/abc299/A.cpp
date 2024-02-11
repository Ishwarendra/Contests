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
    
    int n;
    std::string s;
    std::cin >> n >> s;

    int l = 0, r = 0, x = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '|')
            l = std::min(l, i), r = std::max(r, i);
        else if (s[i] == '*')
            x = i;
    }

    if (l < x and x < r)
        std::cout << "in";
    else
        std::cout << "out";
    
    return 0;
}