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
    char ch;
    std::string s;
    std::cin >> n >> ch >> s;  

    std::map<char, std::vector<int>> pos;
    for (int i = 0; i < n; i++)
    {
        pos[s[i]].emplace_back(i);
        if (s[i] == 'g')
            pos['g'].emplace_back(i + n);
    }

    s += s;
    std::sort(std::begin(pos['g']), std::end(pos['g']));

    int ans = 0;
    for (auto cur : pos[ch])
    {
        auto next = *std::lower_bound(std::begin(pos['g']), std::end(pos['g']), cur);
        ans = std::max(ans, next - cur);
    }

    std::cout << ans << "\n";
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