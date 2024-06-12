#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    std::string s;
    std::cin >> s;
    
    for (int i = 0; i < std::size(s); i++)  
    {
        if (s[i] != s[0])
        {
            std::swap(s[i], s[0]);
            std::cout << "YES\n" << s << "\n";
            return;
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