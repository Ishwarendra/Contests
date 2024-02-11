#include<bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m, x, t, d;
    std::cin >> n >> m >> x >> t >> d;

    if (m >= x)
        std::cout << t;
    else
        std::cout << t - d * (x - m); 
    
    return 0;
}