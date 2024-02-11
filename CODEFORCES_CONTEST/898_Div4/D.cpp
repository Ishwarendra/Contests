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

    int i = 0;
    int ans = 0;
    while (i < n)
    {
        if (s[i] == 'W')
            i++;
        else
        {
            int j = i;
            ans++;
            while (j < i + k and j < n)
                s[j++] = 'W';
            i = j;
        }        
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