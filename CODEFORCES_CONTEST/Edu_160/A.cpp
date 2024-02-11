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

    int i = 1;
    while (i < std::size(s) and s[i] == '0')  
        i++;

    int a = std::stoi(s.substr(0, i));
    int b = i < std::size(s) ? std::stoi(s.substr(i)) : 0;

    if (a < b and a != 0 and b != 0)
        std::cout << a << " " << b << "\n";
    else
        std::cout << "-1\n";
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