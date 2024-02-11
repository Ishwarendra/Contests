#include <bits/stdc++.h>

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

    std::vector<int> zero;
    for (int i = 0; i < n; ++i)  
    {
        if (i + 1 < n and s[i] == '0' and s[i + 1] == '0')
            zero.push_back(i + 1), i++;
        else if (i + 1 < n and s[i] == '0')
            zero.push_back(i);
        else if (s[i] == '0')
            zero.push_back(i);
    }

    std::string ans;
    int pos = 0;
    for (int i = 0; i < n; i++)
    {
        if (pos < std::size(zero) and i + 2 == zero[pos])
        {
            pos++;
            int num = (s[i] - '0') * 10 + (s[i + 1] - '0');
            // take i and i + 1;
            ans += 'a' + num - 1;
            i += 2;
        }
        else
            ans += 'a' + s[i] - '1';
    }

    std::cout << ans << "\n";
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