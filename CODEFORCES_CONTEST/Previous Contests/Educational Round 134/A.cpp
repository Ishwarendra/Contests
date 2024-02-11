#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    std::set<char> s;
    for (int i = 0; i < 4; i++)
    {
        char ch;
        std::cin >> ch;
        s.emplace(ch);
    }

    int n = std::size(s);
    if (n == 4)
        std::cout << "3\n";
    else if (n == 3)
        std::cout << "2\n";
    else if (n == 2)
        std::cout << "1\n";
    else
        std::cout << "0\n";
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