#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    std::string s, t;
    std::cin >> s >> t;
    int n = std::size(s);

    if (s < t)
        std::swap(s, t);

    int found = 0;

    for (int i = 0; i < n; i++)
    {
        if (found == 1)
        {
            if (s[i] > t[i])
                std::swap(s[i], t[i]);
            continue;
        }

        if (s[i] > t[i])
            found = 1;
    }  

    std::cout << s << "\n" << t << "\n";
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