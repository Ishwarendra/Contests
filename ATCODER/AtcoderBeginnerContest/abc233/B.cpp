#include<bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int l, r;
    std::string s;

    std::cin >> l >> r >> s;

    l--, r--;

    std::reverse(s.begin() + l, s.begin() + r + 1);
    std::cout << s << "\n";
    
    return 0;
}