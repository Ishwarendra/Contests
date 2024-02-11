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

    std::vector<int> p(n);
    for (int i = 0; i < n; i++)
        std::cin >> p[i];

    std::prev_permutation(std::begin(p), std::end(p));
    for (int i = 0; i < n; i++)
        std::cout << p[i] << " \n"[i == n - 1];
    
    return 0;
}