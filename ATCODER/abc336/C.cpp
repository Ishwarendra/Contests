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
    
    i64 n;
    std::cin >> n;
    n--;

    std::vector<int> ans;
    while (n)
    {
        ans.emplace_back(2 * (n % 5));
        n /= 5;
    }

    if (ans.empty())
        ans.emplace_back(0);
    std::reverse(std::begin(ans), std::end(ans));

    for (int i = 0; i < std::size(ans); i++)
        std::cout << ans[i];
    
    return 0;
}