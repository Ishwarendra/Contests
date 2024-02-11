#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, k;
    std::cin >> n >> k;

    std::string s;
    std::cin >> s;

    int cnt = std::count(std::begin(s), std::end(s), 'B');
    if (cnt == k)  
        std::cout << "0\n";
    else if (cnt > k)
    {
        std::cout << "1\n";            
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'B')
                cnt--;
            
            if (cnt == k)
            {
                std::cout << i + 1 << " A\n";
                break;
            }
        }
    }
    else
    {
        std::cout << "1\n";
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'A')
                cnt++;
            
            if (cnt == k)
            {
                std::cout << i + 1 << " B\n";
                break;
            }
        }
    }
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