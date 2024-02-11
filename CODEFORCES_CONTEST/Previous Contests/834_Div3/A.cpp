#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

std::string t;
void solve()
{
    std::string s;
    std::cin >> s;

    for (int i = 0; i < std::ssize(t) - std::ssize(s); i++)
    {
        if (t.substr(i, std::size(s)) == s)
        {
            std::cout << "YES\n";
            return;
        }
    }

    std::cout << "NO\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    while (std::size(t) <= 3000)
        t += "Yes";

    int t = 1;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}