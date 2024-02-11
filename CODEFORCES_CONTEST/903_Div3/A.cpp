#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

bool substr(std::string p, std::string s)
{
    int n = std::size(s), m = std::size(p);
    for (int i = 0; i <= n - m; i++)
    {
        if (s.substr(i, m) == p)
            return true;
    }

    return false;
}

void solve()
{
    int n, m;
    std::cin >> n >> m;

    std::string x, s;
    std::cin >> x >> s;

    int cnt = 0, found = 0;;
    while (n < 500)
    {
        if (substr(s, x))
        {
            found = 1;
            break;
        }

        cnt++;
        x += x;
        n = std::size(x);
    }

    std::cout << (found ? cnt : -1) << "\n";
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