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
    std::cin >> n;

    auto get = [&](char f, char s)
    {
        std::string res;
        for (int i = 0; i < n; i++)
            res += std::string(2, i % 2 ? s : f);
        return res;
    };

    char f = '#', s = '.';
    for (int i = 0; i < n; i++)
    {
        std::cout << get(f, s) << "\n" << get(f, s) << "\n";
        std::swap(f, s);
    }
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