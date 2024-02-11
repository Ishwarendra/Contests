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
    std::string s;
    std::cin >> n >> s;

    for (auto &ch : s)
        ch = std::tolower(ch);
    
    s.resize(std::unique(std::begin(s), std::end(s)) - std::begin(s));

    std::string a = "meow";

    std::string ans = "YES\n";

    for (int i = 0; i < std::size(s); i++)  
    {
        if (s[i] != a[i])
            ans = "NO\n";
    }

    if (std::size(s) != 4)
        std::cout << "NO\n";
    else
        std::cout << ans;
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