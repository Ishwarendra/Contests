#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr i64 N = 1e13 + 10;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;

    std::array<int, 10> m{};
    for (int i = 0; i < n; i++)
    {
        char ch;
        std::cin >> ch;
        m[ch - '0']++;
    }

    int ans = 0;

    for (i64 num = 0; num * num <= N; num++)
    {
        if (std::size(std::to_string(num * num)) > n)
            break;

        std::array<int, 10> temp{};
        int cnt = n;
        auto x = num * num;
        while (x)
        {
            temp[x % 10]++;
            x /= 10;
            cnt--;
        }

        if (cnt)
            temp[0] += cnt;

        ans += temp == m;
    }

    std::cout << ans << "\n";
    
    return 0;
}