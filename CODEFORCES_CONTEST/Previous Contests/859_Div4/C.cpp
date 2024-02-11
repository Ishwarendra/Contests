#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    std::string s;
    std::cin >> n >> s;

    auto make = [&](char ch)
    {
        std::string a = s;
        std::map<char, int> change;
        for (int i = 0; i < n; i += 2)
        {
            change[a[i]] = 0;
            a[i] = ch; 
        }

        for (int i = 1; i < n; i += 2)
        {
            if (change.contains(a[i]))
                return false;
        }

        return true;
    };  

    std::cout << (make('0') || make('1') ? "YES\n" : "NO\n");
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