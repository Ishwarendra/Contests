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

    std::vector<int> possible(3);
    std::vector<int> ones;
    for (int i = 0; i < n; i++)  
    {
        if (s[i] == '1')
            ones.push_back(i);
    }

    for (int i = 1; i < std::size(ones); i++)
    {
        int d = ones[i] - ones[i - 1] + 1;
        if (d % 2 == 0)
            possible[0] = 1;
        else
            possible[1] = 1;
    }

    for (int i = 0; i < 3; i++)
    {
        if (possible[i])
        {
            std::cout << i + 1 << "\n";
            return;
        }
    }
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