#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::set<int> s;
    for (int i = 0; i < n; i++)  
    {
        int x;
        std::cin >> x;
        s.emplace(x);
    }

    int rem = 10 - std::ssize(s);

    i64 ans = 1LL * rem * (rem - 1) / 2;

    std::cout << ans * 6LL << "\n";
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