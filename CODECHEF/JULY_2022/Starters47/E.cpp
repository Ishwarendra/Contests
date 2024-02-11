#include <bits/stdc++.h>

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
    
    char n;
    std::cin >> n;

    std::cout << typeid(char).name()[0] == typeid(n).name()[0];
    
    return 0;
}