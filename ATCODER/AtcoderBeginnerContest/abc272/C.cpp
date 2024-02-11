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

    std::vector<int> odd, even;
    for (int i = 0; i < n; i++)
    {
        int x;
        std::cin >> x;
        (x % 2 ? odd : even).push_back(x);
    }

    std::sort(std::begin(odd), std::end(odd));
    std::sort(std::begin(even), std::end(even));

    int max = -1;
    if (odd.size() >= 2)
        max = std::max(max, odd.back() + odd[odd.size() - 2]);
    if (even.size() >= 2)
        max = std::max(max, even.back() + even[even.size() - 2]);

    std::cout << max;
    
    return 0;
}