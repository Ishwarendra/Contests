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

    char min = *std::min_element(std::begin(s), std::end(s));
    int skip = 0;
    for (int i = 0; i < n; i++)  
    {
        if (s[i] == min)
            skip = i;
    }

    std::string t;
    t += min;
    for (int i = 0; i < n; i++)
    {
        if (i == skip)
            continue;
        t += s[i];
    }

    std::cout << t << "\n";
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