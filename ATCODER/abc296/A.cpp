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

    for (int i = 1; i < n; i++)
    {
        if (s[i] == s[i - 1])
        {
            std::cout << "No\n";
            return 0;
        }
    }

    std::cout << "Yes\n";
    
    return 0;
}