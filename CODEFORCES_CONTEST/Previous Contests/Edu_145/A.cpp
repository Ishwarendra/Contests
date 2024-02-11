#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    std::string s;
    std::cin >> s;

    std::map<char, int> m;
    for (auto ch : s)
        m[ch]++;

    if (std::size(m) == 1)
        std::cout << "-1\n";
    else if (std::size(m) == 2 and (std::begin(m)->second == 1 || (++std::begin(m))->second == 1))
        std::cout << "6\n";
    else
        std::cout << "4\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}