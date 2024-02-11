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

    n = std::size(s);

    int max = 0, count = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '-')
            max = std::max(max, count), count = 0;
        else
            count++;
    }

    if (count < n)
        max = std::max(max, count);

    std::cout << (max > 0 ? max : -1) << "\n";
    
    return 0;
}