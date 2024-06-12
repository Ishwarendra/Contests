#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    std::string s;
    std::cin >> s;
    
    if (std::is_sorted(std::begin(s), std::end(s)))
    {
        std::cout << "1\n";
        return;
    }
    
    int n = std::size(s);
    
    int ans = n;
    for (int i = 0; i < n; i++)
    {
        // [0, i - 1] groups [i, j - 1] one group [j to n] groups
        if (s[i] != '0')
            continue;
        
        int cur_ans = (i != 0);
        char prev = s[0];
        for (int id = 0; id < i; id++)
        {
            if (s[id] != prev)
                cur_ans++, prev = s[id];
        }
        
        int j = i;
        prev = s[j];
        cur_ans++;

        while (j < n) 
        {
            if (s[j] != prev)
            {
                prev = s[j];
                if (prev == '0')
                    break;
            }
            
            j++;
        }
        
        cur_ans += j < n;
        for (int id = j; id < n; id++)
        {
            if (s[id] != prev)
                cur_ans++, prev = s[id];
        }
        
        ans = std::min(ans, cur_ans);
    }  
    
    std::cout << ans << "\n";
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