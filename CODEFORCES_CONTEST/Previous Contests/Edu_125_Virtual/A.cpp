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

    std::string ans;
    for (int i = 0; i < n;)
    {
        int count = 0;
        while (i < n and s[i] != '0')
            count++, i++;
        i++;
        ans += std::to_string(count)[0];
    }

    if (s.back() == '0')
        ans += s.back();
    std::cout << ans;
    
    return 0;
}