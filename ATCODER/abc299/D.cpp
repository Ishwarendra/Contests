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

    auto query = [&](int i)
    {
        std::cout << "? " << i + 1 << std::endl;
        char ch;
        std::cin >> ch;
        return ch;
    };

    int left = 0, right = n - 1;
    int ans = 0;

    while (right - left > 1)
    {
        int mid = left + right >> 1;
        char ch = query(mid);

        if (ch == '0')
            left = mid, ans = mid;
        else
            right = mid;
    }

    std::cout << "! " << ans + 1 << std::endl;
    
    return 0;
}