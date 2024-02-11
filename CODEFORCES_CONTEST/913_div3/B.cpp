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

    std::reverse(std::begin(s), std::end(s));
    int u = 0, l = 0;
    std::string ans;

    for (auto ch : s)  
    {
        if (ch == 'b')
            l++;
        else if (ch == 'B')
            u++;
        else
        {
            if (std::islower(ch) and l)
                l--;
            else if (std::isupper(ch) and u)
                u--;
            else
                ans += ch;
        }
    }

    std::reverse(std::begin(ans), std::end(ans));
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