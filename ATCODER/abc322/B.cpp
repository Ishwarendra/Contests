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
    
    int n, m;
    std::string s, t;
    std::cin >> n >> m >> s >> t;

    int x = 0;
    if (t.substr(0, n) == s)
        x |= 2;
    if (t.substr(m - n) == s)
        x |= 1;

    x = 3 - x;
    std::cout << x;
    
    return 0;
}