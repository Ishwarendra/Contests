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
    
    char ch = 'A';
    std::string s;
    std::cin >> s;

    for (int i = 0; i < std::size(s); i++)   
    {
        if (s[i] != ch)
        {
            if (ch == 'C')
            {
                std::cout << "No";
                return 0;
            }
            ch++;
            i--;
        }
    }

    std::cout << "Yes";
    
    return 0;
}