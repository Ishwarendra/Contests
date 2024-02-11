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

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];

    i64 ans = 0;
    std::sort(std::begin(a), std::end(a));

    std::map<int, int> s;
    for (int i = 0; i < n; i++)
        s[a[i]]++;

    for (int i = 0; i < n; i++)
    {
        s[a[i]]--;
        ans += 1LL * i * s[a[i]];
    }

    std::cout << ans << "\n";
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