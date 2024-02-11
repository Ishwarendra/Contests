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
    i64 m;
    std::cin >> n >> m;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    auto b = a;
    std::sort(std::begin(b), std::end(b));

    int sum = 0;
    int my_score = 0, last_win = -1;
    for (int i = 0; i < n and sum + b[i] <= m; i++)
    {
        my_score++, sum += b[i];
        last_win = i;
    }

    std::vector<int> scores;
    if (last_win + 1 < n and last_win + 1 > 0)
    {
        if (m - sum + b[last_win] >= a[last_win + 1])
            my_score++, last_win++;
    }


    scores.emplace_back(my_score);
    for (int i = 0; i < n; i++)
        scores.emplace_back(i + (i > last_win));

    std::sort(std::begin(scores), std::end(scores), std::greater());
    for (int i = 0; i <= n; i++)
    {
        if (scores[i] == my_score)
        {
            std::cout << i + 1 << "\n";
            return;
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