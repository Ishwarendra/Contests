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

    std::vector<int> zero;
    for (int i = 0; i < n; i++)  
    {
        if (s[i] == '0')
            zero.emplace_back(i);
    }

    std::vector<i64> ans(n);
    int pos = std::ssize(zero) - 1;
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == '0')
            continue;

        while (pos >= 0 and zero[pos] > i)
            pos--;

        if (pos < 0)    
        {        
            ans[i] = -1;
            continue;
        }

        ans[i] = i - zero[pos];
        std::swap(s[zero[pos]], s[i]);
        pos--;
    }

    std::reverse(std::begin(ans), std::end(ans));
    
    for (int i = 1; i < n; i++)
    {
        if (ans[i] == -1)
            break;

        ans[i] += ans[i - 1];
    }

    for (int i = 0; i < n; i++)
        std::cout << ans[i] << " \n"[i == n - 1];
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