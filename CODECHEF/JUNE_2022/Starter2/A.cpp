#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif

void solve()
{
    int a, b;
    std::cin >> a >> b;

    int ra = a % 3, rb = b % 3;  
    // std::cout << ra << rb << "\n";
    if (ra == 0 or rb == 0)
        std::cout << "0\n";
    else if (ra == rb)
        std::cout << "1\n";
    else
    {
        std::cout << "2\n";
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    
    while(t--)
        solve();
    
    return 0;
}