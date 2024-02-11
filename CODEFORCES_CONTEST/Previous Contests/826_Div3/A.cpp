#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    std::string s, t;
    std::cin >> s >> t;

    std::array<char, 2> type {};
    for (int i = 0; i < std::max(std::size(s), std::size(t)); i++)
    {
        if (i < std::size(s) and s[i] != 'X')
            type[0] = s[i];
        if (i < std::size(t) and t[i] != 'X')
            type[1] = t[i];
    }  

    if (type[0] < type[1])
        std::cout << ">\n";
    else if (type[0] > type[1])
        std::cout << "<\n";
    else
    {
        int x = std::count(std::begin(s), std::end(s), 'X');
        int y = std::count(std::begin(t), std::end(t), 'X');

        if (x == y)
            std::cout << "=\n";
        else
        {
            if (type[0] == 'S')
                std::cout << (x > y ? "<\n" : ">\n");
            else
                std::cout << (x < y ? "<\n" : ">\n");
        }
    }
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