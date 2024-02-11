#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, a, q;
    std::string s;
    std::cin >> n >> a >> q >> s;

    int read_min = a, same_guy = 0, read_max = a;
    for (int i = 0; i < q; i++)
    {
        if (s[i] == '+')
        {
            if (same_guy)
                same_guy--;
            else
                read_min++;

            read_max++;
        }
        else
            same_guy++;
    }

    if (read_min >= n)
        std::cout << "YES\n";
    else if (read_max >= n)
        std::cout << "MAYBE\n";
    else
        std::cout << "NO\n";
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