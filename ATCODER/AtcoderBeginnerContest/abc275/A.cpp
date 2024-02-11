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

    std::vector<int> h(n);
    for (int i = 0; i < n; i++)
        std::cin >> h[i];

    std::cout << std::max_element(std::begin(h), std::end(h)) - std::begin(h) + 1;
    
    return 0;
}