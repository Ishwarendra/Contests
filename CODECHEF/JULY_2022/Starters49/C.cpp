#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h>
#else
#define trace(...) 1;
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, k;
    std::string s;

    std::cin >> n >> k >> s;

    int zero = std::count(std::begin(s), std::end(s), '0');
    int one = n - zero;

    if (zero < one)
        std::swap(zero, one);

    auto f = [](int num, int k)
    {
        int ceil_count = num % k;
        int floor_count = k - num % k;

        std::vector<std::pair<int, int>> a;
        a.emplace_back(num / k, floor_count);
        a.emplace_back(num / k + 1, ceil_count);

        return a;
    };

    auto z = f(zero, k);
    auto o = f(one, k);

    std::vector<int> ans;

    for (auto &[num1, freq1] : o)
    {
        for (auto &[num0, freq0] : z)
        {
            if (freq0 and freq1)
            {
                ans.emplace_back(abs(num0 - num1));
                int diff = std::min(freq0, freq1);
                freq0 -= diff;
                freq1 -= diff;
            }
        }
    }

    std::cout << *std::max_element(std::begin(ans), std::end(ans)) << "\n";
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