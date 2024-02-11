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
    int k;
    std::cin >> s >> k;  

    int n = std::size(s);
    if (s[0] == '-' and k % 2 == 0)
    {
        std::cout << "-1\n";
        return;
    }   

    if (s[0] == '-')
        s = s.substr(1), n--;

    std::cout << (n + k - 1) / k << "\n";
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