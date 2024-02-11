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

    auto bet = [&](char ch)
    {
        return 'A' <= ch and ch <= 'Z';
    };

    if (std::size(s) != 8 or !bet(s.back()) or !bet(s[0]))
        std::cout << "No\n";
    else
    {
        for (int i = 1; i < 7; i++)
        {
            if ('0' <= s[i] and s[i] <= '9')
                continue;
            else
            {
                std::cout << "No\n";
                std::exit(0);
            }
        }

        int num = std::stoi(s.substr(1, 6));
        if (100000 <= num and num <= 999999)
            std::cout << "Yes\n";
        else
            std::cout << "No\n";
    }
    
    return 0;
}