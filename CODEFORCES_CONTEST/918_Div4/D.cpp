#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

std::set<char> vowels { 'a', 'e', 'i', 'o', 'u' };

void solve()
{
    int n;
    std::string s;
    std::cin >> n >> s;

    std::string ans;
    for (int i = n - 1; i >= 0; i--)
    {
        if (vowels.count(s[i]))
        {
            ans += s[i];
            ans += s[i - 1];
            ans += '.';
            i--;
        }
        else
        {
            ans += s[i];
            ans += s[i - 1];
            ans += s[i - 2];
            ans += '.';
            i -= 2;
        }
    }

    std::reverse(std::begin(ans), std::end(ans));
    std::cout << ans.substr(1) << "\n";
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