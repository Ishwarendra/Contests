#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

void solve()
{
    std::string s;
    std::cin >> s;

    int n = std::size(s);

    std::set<char> distinct;
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (std::size(distinct) < 3)
            distinct.emplace(s[i]);
        else
        {
            if (distinct.count(s[i]))
                continue;
            else
            {
                distinct.clear();
                distinct.emplace(s[i]);
                ans++;
            }
        }
    }  

    ans += !distinct.empty();

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