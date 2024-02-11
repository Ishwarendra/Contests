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
    
    std::map<std::string, int> m;
    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        std::string s;
        std::cin >> s;
        m[s]++;
    }

    if (m["For"] > m["Against"])
        std::cout << "Yes\n";
    else
        std::cout << "No\n";
    
    return 0;
}