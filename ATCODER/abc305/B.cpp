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
    
    std::map<char, int> m;
    m['A'] = 0, m['B'] = 3, m['C'] = 4, m['D'] = 8;
    m['E'] = 9, m['F'] = 14, m['G'] = 23;

    char p, q;
    std::cin >> p >> q;

    std::cout << std::abs(m[q] - m[p]);
    
    return 0;
}