#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::string s, t;
    std::cin >> s >> t;

    int n = std::size(s), m = std::size(t);

    std::vector<int> suff(m + 1), pref(m + 1);
    pref[0] = 1, suff[m] = 1;

    for (int pos = m - 1, i = n - 1, j = m - 1; j >= 0; j--, i--, pos--)
    {
        if (s[i] == '?' or t[j] == '?' or (s[i] == t[j]))
            suff[pos] = suff[pos + 1];
    }

    for (int pos = 1, i = 0, j = 0; j < m; i++, j++, pos++)
    {
        if (s[i] == '?' or t[j] == '?' or (s[i] == t[j]))
            pref[pos] = pref[pos - 1];
    }

    for (int x = 0; x <= m; x++)
    {
        if (suff[x] and pref[x])
            std::cout << "Yes\n";
        else
            std::cout << "No\n";
    }
    
    return 0;
}