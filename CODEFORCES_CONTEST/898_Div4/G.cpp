#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    std::string s;
    std::cin >> s;

    int n = std::size(s);
    std::vector<int> pos(1, -1);
    std::vector dp(n, std::array<int, 2>());

    for (int i = 0; i < n; i++)  
    {
        if (s[i] == 'B')
            pos.emplace_back(i);
    }

    pos.emplace_back(n);
    std::multiset<int> as;
    for (int i = 1; i < std::ssize(pos); i++)
        as.emplace(pos[i] - pos[i - 1] - 1);
    
    if (!as.empty() or *std::begin(as) != 0)
        as.erase(std::begin(as));
    std::cout << std::accumulate(std::begin(as), std::end(as), 0) << "\n";
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