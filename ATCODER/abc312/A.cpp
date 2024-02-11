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
    
    std::set<std::string> s {"ACE", "BDF", "CEG", "DFA", "EGB", "FAC", "GBD"};
    std::string a;
    std::cin >> a;

    std::cout << (s.count(a) ? "Yes" : "No");
    
    return 0;
}