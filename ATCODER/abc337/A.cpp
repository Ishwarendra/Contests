#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;

    int x = 0, y = 0;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        std::cin >> a >> b;
        x += a, y += b;
    }

    if (x == y)
        std::cout << "Draw";
    else if (x > y)
        std::cout << "Takahashi";
    else
        std::cout << "Aoki";
    
    return 0;
}