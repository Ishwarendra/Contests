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
    
    auto t = s;
    std::sort(std::begin(t), std::end(t));
    t.erase(std::unique(std::begin(t), std::end(t)), std::end(t));
    
    int sz = std::size(t);
    for (auto &ch : s)
    {
        int id = t.find(ch);
        ch = t[sz - id - 1];
    }  
    
    std::cout << s << "\n";
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