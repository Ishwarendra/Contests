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
    std::string s;
    std::cin >> n >> k >> s;  

    if (k % 2 == 0)
    {
        std::sort(std::begin(s), std::end(s));
        std::cout << s << "\n";
    }
    else
    {
        std::string s1, s2;
        for (int i = 0; i < n; i++)
            (i % 2 ? s2 : s1) += s[i];

        std::sort(std::begin(s2), std::end(s2));
        std::sort(std::begin(s1), std::end(s1));

        s.clear();
        for (int i = 0, pos1 = 0, pos2 = 0; i < n; i++)
            s += (i % 2 ? s2[pos2++] : s1[pos1++]);

        std::cout << s << "\n";
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