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

    if (std::count(std::begin(s), std::end(s), 'o') > 0
        and std::count(std::begin(s), std::end(s), 'x') == 0)
        std::cout << "Yes";
    else
        std::cout << "No";
    
    return 0;
}