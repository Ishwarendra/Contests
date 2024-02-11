#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    std::string x;
    std::cin >> x;

    x = '0' + x;
    int n = std::size(x);
    int last = n;

    for (int i = n - 2; i >= 0; i--)  
    {
        if (x[i + 1] >= '5' and x[i] < '9')
            x[i]++, x[i + 1] = '0', last = i;
    }

    if (x.front() == '0')
        x = x.substr(1);
    
    for (int i = last + 1; i < n; i++)
        x[i] = '0';

    std::cout << x << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}