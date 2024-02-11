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

    int aoki = std::count(std::begin(s), std::end(s), 'A');
    int taka = n - aoki;

    if (taka == aoki)
        std::cout << (s.back() == 'A' ? 'T' : 'A');
    else
        std::cout << (aoki > taka ? 'A' : 'T');
    
    return 0;
}