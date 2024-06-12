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

    for (int len = n; len >= 2; len--)
    {
        std::vector<int> a(len);
        for (int i = 0; i < n; i++)
            a[i % len] ^= (s[i] == '0');

        if (std::size(std::set(std::begin(a), std::end(a))) == 1)
        {
            std::cout << len << "\n";
            return;
        }
    }

    std::cout << "1\n";
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