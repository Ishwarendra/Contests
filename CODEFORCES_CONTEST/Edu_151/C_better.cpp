#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    std::string s, l, r;
    int m;
    std::cin >> s >> m >> l >> r;   

    int n = std::size(s);

    std::vector next(n + 2, std::vector(10, n + 1));
    for (int i = n - 1; i >= 0; i--)
    {
        next[i] = next[i + 1];
        next[i][s[i] - '0'] = i + 1;
    }

    int end = 0;
    for (int i = 0; i < m; i++)
    {
        int max = end;
        for (char ch = l[i]; ch <= r[i]; ch++)
            max = std::max(max, next[end][ch - '0']);
        end = max;
    }
    print(end)
    std::cout << (end <= n ? "NO\n" : "YES\n");
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