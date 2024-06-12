#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, m;
    std::cin >> n >> m;
    
    std::map<char, int> cnt;
    for (int i = 0; i < n; i++)  
    {
        char ch;
        std::cin >> ch;
        cnt[ch]++;
    }
    
    int ans = 0;
    for (char ch = 'A'; ch <= 'G'; ch++)
    {
        if (cnt[ch] < m)
            ans += m - cnt[ch];
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