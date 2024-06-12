#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    std::string s;
    std::cin >> n >> s;
    
    std::map<char, int> cnt;
    std::map<char, std::vector<int>> pos;
    for (int i = 0; auto ch : s)
    {
        cnt[ch]++;
        pos[ch].emplace_back(i++);
    }
    
    std::string ans(n, 'R');
    auto update = [&](char ch, char put = 'H')
    {  
        if (put == 'H')
            ans[pos[ch].back()] = put;
        pos[ch].pop_back();
    };
    
    int ok = 0;
    
    if (cnt['N'] % 2 and cnt['S'] % 2)
    {
        cnt['N']--, cnt['S']--, ok = 1;
        update('N');
        update('S');
    }
    
    if (cnt['W'] % 2 and cnt['E'] % 2)
    {
        cnt['W']--, cnt['E']--;
        update('W', ok + 'H');
        update('E', ok + 'H');
    }
    
    for (auto &[ch, f] : cnt)
    {
        if (f % 2)
        {
            std::cout << "NO\n";
            return;
        }
    }
    
    for (auto &[ch, p] : pos)
    {
        if (p.empty())
            continue;

        for (int i = 0; i < std::size(p); i += 2)
            ans[p[i]] = 'H';
    }
    
    if (std::size(std::set(std::begin(ans), std::end(ans))) == 1)
        std::cout << "NO\n";
    else
        std::cout << ans << '\n';
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