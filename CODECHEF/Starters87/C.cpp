#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

const std::string first = "CHEF";
const std::string second = "CHEFINA";

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    i64 sum = std::accumulate(std::begin(a), std::end(a), 0LL);
    if (n % 2 == 1)
        std::cout << (sum % 2 ? first : second) << "\n";
    else
    {
        int min = *std::min_element(std::begin(a), std::end(a));

        if (sum % 2 or min % 2)
            std::cout << first << "\n";
        else
            std::cout << second << "\n"; 
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}