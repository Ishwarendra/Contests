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
    
    int n;
    std::string s;
    std::cin >> n >> s;

    int sz = std::size(s);
    std::string last = s;
    for (int mask = 0; mask < (1 << sz); mask++)
    {
        if (__builtin_popcount(mask) > n)
            continue;

        std::string ans;

        for (int i = 0; i < sz; i++)
        {
            if ((mask >> i) & 1)
                continue;
            ans += s[i];
        }

        if (ans.empty())
            ans = "0";
        int x = std::stoi(ans);
        ans = std::to_string(x);
        last = std::min(last, ans);
    }

    std::cout << last;
    
    return 0;
}