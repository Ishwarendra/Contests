#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, s;
    std::cin >> n >> s;

    std::vector<int> b(n);
    for (int i = 0; i < n; i++)
        std::cin >> b[i];

    int cur_sum = std::accumulate(std::begin(b), std::end(b), 0);
    std::sort(std::begin(b), std::end(b));
    
    std::vector<int> a(*std::max_element(std::begin(b), std::end(b)));
    std::iota(std::begin(a), std::end(a), 1);

    if (std::accumulate(std::begin(a), std::end(a), 0LL) > s + cur_sum)
        std::cout << "NO\n";
    else
    {
        cur_sum += s;
        cur_sum -= std::accumulate(std::begin(a), std::end(a), 0);

        int max = std::size(a) + 1;
        for (int i = max; ; i++)
        {
            if (cur_sum == 0)
            {
                std::cout << "YES\n";
                return;
            }
            else if (cur_sum < 0)
            {
                std::cout << "NO\n";
                return;
            }

            cur_sum -= i;
        }
    }
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