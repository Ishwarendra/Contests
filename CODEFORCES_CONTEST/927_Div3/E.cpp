#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    int st = 0;
    while (st < n and s[st] == '0')
        st++;
    s = s.substr(st);
    n = std::size(s);

    std::vector<int> p(n);
    for (int i = 0; i < n; i++)
    {
        if (i)
            p[i] = p[i - 1];
        p[i] += s[i] - '0';
    }

    int carry = 0;
    std::string ans;
    for (int i = n - 1; i >= 0; i--)
    {
        int total = p[i] + carry;
        ans += char('0' + total % 10);
        carry = total / 10;
    }

    while (carry)
    {
        ans += char('0' + carry % 10);
        carry /= 10;
    }

    std::reverse(std::begin(ans), std::end(ans));
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