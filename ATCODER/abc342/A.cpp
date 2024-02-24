#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::map<char, int> m;
    std::string s;
    std::cin >> s;

    for (auto ch : s)
        m[ch]++;

    for (auto &[ch, f] : m)
    {
        if (f == 1)
        {
            for (int i = 0; i < std::size(s); i++)
            {
                if (ch == s[i])
                {
                    std::cout << i + 1;
                    return 0;
                }
            }
        }
    }
    
    return 0;
}