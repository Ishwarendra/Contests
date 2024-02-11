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
    
    int n, k;
    std::cin >> n >> k;

    std::vector<int> sock;
    for (int i = 0; i < k; i++)
    {
        int a;
        std::cin >> a;
        sock.emplace_back(a - 1);
    }

    auto work = [&]() -> i64
    {
        if (std::size(sock) == 1)
            return 0;

        i64 left = 0, right = 0;

        for (int i = 1; i < std::size(sock); i += 2)
            right += std::abs(sock[i + 1] - sock[i]);

        i64 ans = right;
        for (int i = 0; i < std::size(sock); i += 2)
        {
            i64 cur = right + left;
            ans = std::min(ans, cur);

            right -= std::abs(sock[i + 2] - sock[i + 1]);
            left += std::abs(sock[i + 1] - sock[i]);
        }

        return ans;
    };

    if (k % 2 == 0)
    {
        i64 ans = 0;
        for (int i = 0; i < std::size(sock); i += 2)
            ans += sock[i + 1] - sock[i];

        std::cout << ans;
    }
    else
    {
        i64 ans = work();
        std::reverse(std::begin(sock), std::end(sock));
        ans = std::min(ans, work());

        std::cout << ans;
    }

    return 0;
}