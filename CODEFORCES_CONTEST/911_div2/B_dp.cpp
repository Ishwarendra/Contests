#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

int dp[301][301][301][3];

int f(int a, int b, int c, int id)
{
    if (a < 0 or b < 0 or c < 0)
        return 0;

    if (a == 0 and b == 0 and c == 0)
        return 0;

    auto &cur = dp[a][b][c][id];
    if (dp[a][b][c][id] != -1)
        return cur;

    cur = f(a - 1, b - 1, c + 1, id)
        || f(a - 1, b + 1, c - 1, id)
        || f(a + 1, b - 1, c - 1, id);

    return cur;
}

void solve()
{
    int a, b, c;
    std::cin >> a >> b >> c;

    for (int i = 0; i < 3; i++)
        std::cout << f(a, b, c, i) << " \n"[i == 2];
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    std::memset(dp, -1, sizeof dp);
    const int N = 301;
    for (int i = 1; i < N; i++)
    {
        dp[i][0][0][0] = 1;
        dp[0][i][0][1] = 1;
        dp[0][0][i][2] = 1;
    }

    while (t--)
        solve();

    return 0;
}