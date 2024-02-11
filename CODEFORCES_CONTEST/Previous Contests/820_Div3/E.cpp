#include <bits/stdc++.h>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

int count = 0;

i64 query(i64 x, i64 y)
{ 
    count++;
    assert(count <= 50);
    std::cout << "? " << x << " " << y << std::endl;
    i64 len;
    std::cin >> len;

    return len;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
        
    i64 pans = 0;
    for (int j = 2; j <= 26; j++)
    {
        i64 l1 = query(1, j);
        i64 l2 = query(j, 1);

        if (l1 != l2)
        {
            std::cout << "! " << l1 + l2 << std::endl;
            return 0;
        }
        else
            pans = std::max(pans, l1 * 2);
    }

    std::cout << "! " << pans << std::endl;
    
    return 0;
}