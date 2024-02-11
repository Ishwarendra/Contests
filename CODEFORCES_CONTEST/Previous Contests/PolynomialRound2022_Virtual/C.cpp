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

    std::array<int, 2> found{1, 1};
    for (int i = 2; i <= n; i++)
    {
        found[s[i - 2] - '0'] = i;
        if (s[i - 2] == '1')
            std::cout << found[0] << " ";
        else
            std::cout << found[1] << " ";
    }

    std::cout << "\n";
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