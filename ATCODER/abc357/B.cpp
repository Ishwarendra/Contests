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
    
    std::string s;
    std::cin >> s;
    
    int lower = 0, upper = 0;
    for (auto ch : s)
    {
        lower += 'a' <= ch and ch <= 'z';
        upper += 'A' <= ch and ch <= 'Z';
    }
    
    if (lower < upper)
    {
        for (auto ch : s)
        {
            if ('a' <= ch and ch <= 'z')
                std::cout << char('A' + ch - 'a');
            else
                std::cout << ch;
        }
    }
    else
    {
        for (auto ch : s)
        {
            if ('A' <= ch and ch <= 'Z')
                std::cout << char('a' + ch - 'A');
            else
                std::cout << ch;
        }
    }
    
    return 0;
}