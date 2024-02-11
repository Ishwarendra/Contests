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
    
    std::string s;
    std::cin >> s;

    std::map<char, std::vector<int>> pos;
    for (int i = 0; i < std::size(s); i++)
        pos[s[i]].emplace_back(i);

    if (pos['B'][0] % 2 == pos['B'][1] % 2)
    {
        std::cout << "No";
        return 0;
    }

    if (pos['R'][0] <= pos['K'][0] and pos['K'][0] <= pos['R'][1])
        std::cout << "Yes";
    else
        std::cout << "No";

    return 0;
}