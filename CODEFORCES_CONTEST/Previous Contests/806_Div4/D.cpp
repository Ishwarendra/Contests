#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

void solve()
{
    int n;
    std::cin >> n;

    std::vector<std::string> a(n);
    std::set<std::string> s;
    for (int i = 0; i < n; ++i)  
    {
        std::cin >> a[i];
        s.insert(a[i]);
    }

    std::string ans;
    for (int i = 0; i < n; ++i)
    {
        int m = std::size(a[i]);
        char ch = '0';

        for (int j = 0; j < m - 1; j++)
        {
            if (s.count(a[i].substr(0, j + 1)) and s.count(a[i].substr(j + 1)))
                ch = '1';
        }

        ans += ch;
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