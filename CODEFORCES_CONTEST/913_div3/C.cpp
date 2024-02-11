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

    std::array<int, 26> a{};
    int max = 0;
    for (auto ch : s) 
    { 
        a[ch - 'a']++;
        max = std::max(max, a[ch - 'a']);
    }

    std::cout << std::max(n % 2, 2 * max - n) << '\n';
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