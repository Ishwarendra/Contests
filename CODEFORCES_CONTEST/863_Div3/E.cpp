#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    i64 k;
    std::cin >> k;

    std::vector<int> a;
    while (k)  
    {
        a.push_back(k % 9);
        k /= 9;
    }

    for (int i = 0; i < std::size(a); i++)
    {
        if (a[i] >= 4)
            a[i]++;
    }

    std::reverse(std::begin(a), std::end(a));
    for (int i = 0; i < std::size(a); i++)
        std::cout << a[i];
    std::cout << "\n";
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