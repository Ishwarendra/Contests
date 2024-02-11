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
    
    int x, y;
    std::cin >> x >> y;

    std::cout << std::max(0, y - x + 9) / 10 << "\n";
    
    return 0;
}