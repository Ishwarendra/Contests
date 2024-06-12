#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    const int n = 3;
    std::vector a(n, std::vector<i64>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            std::cin >> a[i][j];
    }

    // 1 -> taka, 2 -> aoki
    int cnt = 0;
    std::vector vis(n, std::vector(n, 0));
    std::array<i64, 3> score{};

    auto row_same = [&](int r, int x)
    {
        return std::count(std::begin(vis[r]), std::end(vis[r]), x) == 3;
    };

    auto col_same = [&](int c, int x)
    {
        return vis[0][c] == vis[1][c] and vis[1][c] == vis[2][c] and vis[0][c] == x;
    };

    auto diag = [&](int x)
    {
        int cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < n; i++)
            cnt1 += vis[i][i] == x, cnt2 += vis[i][n - i - 1] == x;

        return cnt1 == 3 or cnt2 == 3;
    };

    auto winBoard = [&](int x)
    {
        for (int i = 0; i < n; i++)
        {
            if (row_same(i, x))
                return true;
            if (col_same(i, x))
                return true;
        }

        return diag(x);
    };

    auto winCheck = [&]()
    {
        i64 aoki = 0, taka = 0;
        if (winBoard(1))
            return 1;
        if (winBoard(2))
            return 2;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (vis[i][j] == 0)
                    return 0;
                else if (vis[i][j] == 1)
                    taka += a[i][j];
                else
                    aoki += a[i][j];
            }
        }

        return (taka > aoki ? 1 : 2);
    };

    auto f = [&](auto &&self, int turn) -> int
    {
        int ans = winCheck();
        if (ans)
            return ans;

        int win = 0;
        for (int i = 0; i < n and win == 0; i++)
        {
            for (int j = 0; j < n and win == 0; j++)
            {
                if (vis[i][j] == 0)
                {
                    vis[i][j] = turn;
                    score[turn] += a[i][j];
                    cnt++;

                    int winner = self(self, 3 - turn);
                    if (winner == turn)
                        win = 1;

                    score[turn] -= a[i][j];
                    vis[i][j] = 0;
                    cnt--;
                }
            }
        }

        if (win)
            return turn;
        return 3 - turn;
    };

    std::cout << (f(f, 1) == 1 ? "Takahashi" : "Aoki");

    return 0;
}