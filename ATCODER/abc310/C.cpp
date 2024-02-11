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
    std::cin >> n;

    std::set<std::string> a;
    for (int i = 0; i < n; i++)
    {
        std::string s;
        std::cin >> s;

        if (a.count(s) or a.count(std::string(std::rbegin(s), std::rend(s))))
            continue;
        a.emplace(s);
    }

    std::cout << std::size(a);
    
    return 0;
}