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
    
    int a = 4;
    int b = a - 1;
    
    std::set<int> s;
    int xx = 8;
    for (int p = 0; p <= xx; p++)
    {
        for (int q = 0; q <= xx; q++)
        {
            s.emplace(a*p + b*q);
        }
    }
    
    int cnt = 0;

    for (auto x : s)
    {
        std::cout << x << " ";
        cnt++;
        if (cnt % 8 == 0)
            std::cout << "\n";
    }
    
    return 0;
}