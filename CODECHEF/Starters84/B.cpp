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

    auto f = [&](char ch)
    {
        std::string x;
        x += ch;

        for (int i = 0; i < n - 1; i++)
        {
            int a = s[i] - '0', b = x[i] - '0';
            if (a ^ b)
                x += '1';
            else
                x += '0';
        }

        return std::count(std::begin(x), std::end(x), '1');
    };  

    std::cout << std::max(f('0'), f('1')) << "\n";
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