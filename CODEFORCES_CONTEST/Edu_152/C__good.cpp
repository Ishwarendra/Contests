#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, m;
    std::string s;
    std::cin >> n >> m >> s;

    std::set<std::string> a;
    for (int i = 0; i < m; i++)  
    {
        int l, r;
        std::cin >> l >> r;
        auto t = s;

        std::sort(std::begin(s) + l - 1, std::begin(s) + r);
        a.emplace(s);
        s = t;

        print(a)
    }

    std::cout << std::size(a) << '\n';
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