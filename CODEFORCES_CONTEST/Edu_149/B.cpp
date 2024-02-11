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

    auto get = [&](auto ch)
    {   
        int cnt = 0;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == ch)
                cnt++;
            else
                ans = std::max(ans, cnt), cnt = 0;
        }

        ans = std::max(ans, cnt);
        return ans;
    };

    std::cout << std::max(get('<'), get('>')) + 1 << "\n";
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