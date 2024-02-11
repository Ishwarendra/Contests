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
    
    std::string pi = "3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679";

    int n;
    std::cin >> n;

    std::cout << pi.substr(0, n + 2);
    
    return 0;
}