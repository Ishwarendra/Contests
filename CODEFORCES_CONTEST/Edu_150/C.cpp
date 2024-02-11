#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

int pw[6] {};

constexpr i64 inf = 1e18;

auto brute(std::string &t)
{
    i64 sum = 0;
    int n = std::size(t);
    char maxc = '\0';
    for (int i = n - 1; i >= 0; i--)
    {
        if (maxc > t[i])
            sum -= pw[t[i] - 'A'];
        else
            sum += pw[t[i] - 'A'];

        maxc = std::max(maxc, t[i]);
    }

    return sum;
};

void solve()
{
    std::string s;
    std::cin >> s;

    int n = std::size(s);

    i64 ans = -inf;

    std::array<int, 5> min, max{};
    std::fill(std::begin(min), std::end(min), n - 1);

    for (int pos = 0; auto ch : s)
    {
        min[ch - 'A'] = std::min(min[ch - 'A'], pos);
        max[ch - 'A'] = std::max(max[ch - 'A'], pos);
        pos++;
    }

    for (int i = 0; i < 5; i++)
    {
        for (char ch = 'A'; ch <= 'E'; ch++)
        {
            auto old = s[min[i]];
            s[min[i]] = ch;
            ans = std::max(ans, brute(s));
            s[min[i]] = old;

            old = s[max[i]];
            s[max[i]] = ch;
            ans = std::max(ans, brute(s));
            s[max[i]] = old;
        }
    }

    std::cout << ans << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    pw[0] = 1;
    for (int i = 1; i <= 5; i++)
        pw[i] = pw[i - 1] * 10;
    
    int t;
    std::cin >> t;

    while (t--)
        solve();

    return 0;
}