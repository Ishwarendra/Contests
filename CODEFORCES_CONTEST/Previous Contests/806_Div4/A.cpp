#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

void solve()
{
    std::string s;
    std::cin >> s;

    std::for_each(std::begin(s), std::end(s), [](char &ch) {return std::toupper(ch);});
    print(s)
    // bool cond = (s[0] == 'Y' or s[0] == 'y');
    // cond &= (s[1] == 'E' or s[1] == 'e');
    // cond &= (s[2] == 's' or s[2] == 'S');

    // std::cout << (cond ? "YES\n" : "NO\n");  
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}