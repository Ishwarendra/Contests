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
    
    std::set<char> chars {'a', 't', 'c', 'o', 'd', 'e', 'r'};    
    std::string s, t;
    std::cin >> s >> t;

    std::array<int, 26> cnts{}, cntt{};
    int extras = 0, extrat = 0;

    for (auto ch : s)
    {
        if (ch == '@')
            extras++;
        else
            cnts[ch - 'a']++;
    }
    for (auto ch : t)
    {
        if (ch == '@')
            extrat++;
        else
            cntt[ch - 'a']++;
    }

    for (int i = 0; i < 26; i++)
    {
        if (cnts[i] == cntt[i])
            continue;
        char ch = char(i + 'a');
        int d = std::abs(cnts[i] - cntt[i]);
        if (!chars.count(ch))
        {
            std::cout << "No";
            return 0;
        }
        if (cnts[i] > cntt[i] and extrat < d)
        {
            std::cout << "No";
            return 0;
        }
        else if (cnts[i] > cntt[i])
            extrat -= d;

        if (cnts[i] < cntt[i] and extras < d)
        {
            std::cout << "No";
            return 0;
        }
        else if (cnts[i] < cntt[i])
            extras -= d;
    }

    std::cout << "Yes";
    
    return 0;
}