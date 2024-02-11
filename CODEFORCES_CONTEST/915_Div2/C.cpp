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

    std::string suff_max;
    suff_max += s.back();

    for (int i = n - 2; i >= 0; i--)  
        suff_max += std::max(suff_max.back(), s[i]);

    std::reverse(std::begin(suff_max), std::end(suff_max));
    std::string max;

    for (int i = 0; i < n; i++)
    {
        if (suff_max[i] == s[i])
            max += s[i];
    }

    std::sort(std::begin(max), std::end(max));
    std::string t;
    for (int i = 0, j = 0; i < n; i++)    
    {
        if (suff_max[i] == s[i])
            t += max[j++];
        else
            t += s[i];
    }

    if (!std::is_sorted(std::begin(t), std::end(t)))
        std::cout << "-1\n";
    else
    {
        int cnt = std::count(std::begin(max), std::end(max), max.back());
        std::cout << std::ssize(max) - cnt << "\n";
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