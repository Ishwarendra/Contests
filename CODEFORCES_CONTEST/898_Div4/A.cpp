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

    for (int i = 0; i < 3; i++)  
    {
        for (int j = 0; j < 3; j++)
        {
            std::swap(s[i], s[j]);
            if (s == "abc")
            {
                std::cout << "YES\n";
                return;
            }
            std::swap(s[i], s[j]);
        }
    }

    std::cout << "NO\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}