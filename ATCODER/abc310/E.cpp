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

    std::array<i64, 2> cnt{};
    i64 ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            cnt[1] += cnt[0];
            cnt[0] = 1;
            ans += cnt[1];
        }
        else
        {
            std::swap(cnt[0], cnt[1]);
            cnt[1]++;
            ans += cnt[1];
        }
    }

    std::cout << ans;
    
    return 0;
}