#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, p;
    std::cin >> n >> p;

    for (int i = 0; i < n - 1; i++)
    {
        int nex;
        std::cin >> nex;
        std::cout << p * nex << " ";
        p = nex;
    }
    
    return 0;
}