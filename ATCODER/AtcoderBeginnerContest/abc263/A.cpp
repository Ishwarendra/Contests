#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::vector<int> a(16);
    for (int i = 0; i < 5; ++i)
    {
        int x;
        std::cin >> x;

        a[x]++;
    }

    for (int i = 0; i < 16; i++)
    {
        if (a[i] != 0 and a[i] != 3 and a[i] != 2)
        {
            std::cout << "No\n";
            return 0;
        }
    }

    std::cout << "Yes\n";
    
    return 0;
}